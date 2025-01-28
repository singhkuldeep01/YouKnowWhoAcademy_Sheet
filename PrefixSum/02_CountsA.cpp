#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> temp(n,0);
    if(s[0] == 'a') temp[0] = 1;
    for(int i = 1 ; i < n ; i++){
        temp[i] += temp[i-1];
        if(s[i] == 'a') temp[i]++;
    }
    int q;
    cin>>q;
    while(q--){
        int a , b ;
        cin>>a>>b;
        a--;
        b--;
        int f = 0;
        int s = 0;
        if(a > 0) f = temp[a-1];
        s = temp[b];
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