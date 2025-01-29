#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++) cin>>vec[i];
    int t = vec[0];
    for(int i  = 1 ; i < n ; i++){
        t = __gcd(t , vec[i]);
    }
    if(t == 1){
        cout<<0<<endl;
    }else{
        if(__gcd(t, __gcd(n,vec[n-1])) == 1){
            cout<<1<<endl;
        }else if(__gcd(t, __gcd(n-1,vec[n-2])) == 1){
            cout<<2<<endl;
        }else{
            cout<<3<<endl;
        }
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
    cin>>t;
    while(t--) solve();
    return 0;
}