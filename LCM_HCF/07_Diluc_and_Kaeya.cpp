#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
double findSlope(double x , double y){
    if(x == 0) return INF;
    else return double (y-0)/(x-0);
}
void solve() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    unordered_map<double , int> mp;
    int x = 0,y = 0;
    vector<int> ans(n,1);
    for(int i = 0 ; i < n ; i++){
        if(str[i] == 'D') x++;
        else y++;
        double slope = findSlope(x,y);
        if(mp[slope])
            ans[i] = mp[slope] + 1;
        mp[slope]++;
    }
    for(auto ele  : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
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