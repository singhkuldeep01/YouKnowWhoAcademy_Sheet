#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n = 1;
    vector<int> vec;
    while(n){
        n = INT_MIN;
        cin>>n;
        if(n == INT_MIN) break;
        vec.push_back(n);
    }
    unordered_map<int,int> mp;
    for(auto ele : vec) mp[ele]++;
    for(int i = 0 ; i < vec.size() ; i++){
        if(mp[vec[i]]){
            cout<<vec[i]<<" "<<mp[vec[i]]<<endl;
        }
        mp[vec[i]] = 0;
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