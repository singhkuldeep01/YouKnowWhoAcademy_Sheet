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
    for(int i = 0 ; i < n  ; i++) cin>>vec[i];
    vector<int> temp;
    int len = n*(n+1)/2;
    for(int i = 0 ; i < n ; i++){
        temp.push_back(vec[i]);
        for(int j = i+1 ; j < n ; j++){
            temp.push_back(temp[temp.size()-1] + vec[j]);
        }
    }
    for(int i = 1; i < temp.size() ; i++){
        temp[i] += temp[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l , r;
        cin>>l>>r;
        l--;
        r--;
        int f = 0;
        int s = 0;
        if(l > 0) f = temp[l-1];
        s = temp[r];
        cout<<s-f<<endl;
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
    //cin>>t;
    while(t--) solve();
    return 0;
}