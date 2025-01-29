#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n ;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    unordered_map<int,int> mp;
    mp[0] = 0;
    int prefixSum = 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        prefixSum += v[i];
        prefixSum %= 7;
        if(mp.find(prefixSum) != mp.end()){
            ans = max(ans , i - mp[prefixSum]);
        }
        if(mp.find(prefixSum) == mp.end()){
            mp[prefixSum] = i;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}

// 3 5 1 6 2 14 10
// 3 8 9 15 17 31 41
// 3 1 2 1 3 3 6
