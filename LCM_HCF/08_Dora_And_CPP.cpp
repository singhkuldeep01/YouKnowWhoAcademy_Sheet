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
    int a , b;
    vector<int> vec(n);
    cin>>a>>b;
    int g = __gcd(a,b);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    for(int i = 0 ; i < n ; i++){
        vec[i] = vec[i] % g;
    }
    sort(vec.begin(), vec.end());
    int ans = vec[n-1] - vec[0];
    for(int i = 0 ; i < n-1 ; i++){
        ans = min(ans , vec[i] + g - vec[i+1]);
    }
    cout<<ans<<endl;
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