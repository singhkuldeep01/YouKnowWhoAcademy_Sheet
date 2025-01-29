#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , tar;
    cin>>n>>tar;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++) cin>>vec[i];
    map<int,int> mp;
    mp[0] = 1;
    int count = 0;
    int prefixSum = 0;
    for(int i = 0 ; i < n ; i++){
        prefixSum += vec[i];
        if(mp.find(prefixSum-tar) != mp.end())
            count += mp[prefixSum - tar];
        mp[prefixSum]++;
    }
    cout<<count<<endl;
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