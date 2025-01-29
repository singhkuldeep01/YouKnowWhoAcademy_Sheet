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
    unordered_map<int,int> mp;
    for(int i = 0 ; i < n ;i++) {
        int ele;
        cin>>ele;
        if(ele <=  n)
        mp[ele]++;
    }
    vector<int> temp(n+1,0);
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j += i){
            temp[j] += mp[i];
        }
    }
    for(int i = 0 ; i <= n ; i++){
            ans = max(ans , temp[i]);
    }
    cout<<ans<<endl;
}

/*
    Frog 1: 0→1→2→3→4→⋯
    Frog 2: 0→2→4→6→8→⋯
    Frog 3: 0→3→6→9→12→⋯
    Frog 4: 0→4→8→12→16→⋯
    Frog 5: 0→5→10→15→20→⋯
*/

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