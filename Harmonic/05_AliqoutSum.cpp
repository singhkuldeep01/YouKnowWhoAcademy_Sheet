#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e6 + 1
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    vector<int> divisor(INF,0);
    for(int i = 1; i <= INF ; i++){
        for(int j = i ; j <= INF ; j+=i){
            divisor[j] += i;
        }
        divisor[i] -= i;
    }
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(divisor[a] > a){
            cout<<"abundant";
        }else if(divisor[a] < a){
            cout<<"deficient";
        }else{
            cout<<"perfect";
        }
        cout<<endl;
    }
}

int32_t main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    fast_io;
    int t = 1;
    // cin>>t;
    while(t--) solve();
    return 0;
}