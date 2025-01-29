#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n,q;
    cin>>n;
    vector<int> v1(n);
    for(int i = 0 ; i < n ; i++) cin>>v1[i];
    cin>>q;
    vector<int>v2 = v1;
    sort(v2.begin(),v2.end());
    for(int i = 1 ; i < n ; i++){
        v1[i] += v1[i-1];
        v2[i] += v2[i-1];
    }
    while(q--){
        int type , l , r;
        cin>>type>>l>>r;
        l--;
        r--;
        int f = 0;
        int s = 0;
        if(type == 1){
            if(l > 0) f =  v1[l-1];
            s = v1[r];
            cout<<s-f<<endl;
        }else{
            f = 0;
            s = 0;
            if(l > 0) f = v2[l-1];
            s = v2[r];
            cout<<s-f<<endl;
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
    //cin>>t;
    while(t--) solve();
    return 0;
}