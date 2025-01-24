#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

int f2(int i ,vector<vector<int>> &vec , int curr  ){
    if(i >= vec.size()) return 0;
    int select = 0;
    int noSelect = 0;
    if(curr >= vec[i][0]){
        select = vec[i][1] + f2(i+1 , vec , curr - vec[i][0]);
    }
    noSelect = f2(i+1 , vec , curr);
    return max(select , noSelect);
}


void solve() {
    int n,w;
    cin>>n>>w;
    vector<vector<int>> vec(n , vector<int> (2));
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    // int subSets = 1 << n;
    // int ans = 0;
    // for(int mask = 0 ; mask < subSets ; mask++){
    //     int weight = w;
    //     int res = 0;
    //     for(int i = 0 ; i < n ; i++){
    //         if(mask & (1<<i) && weight >= vec[i][0]){
    //             res += vec[i][1];
    //             weight -= vec[i][0];
    //         }
    //     }
    //     ans = max(ans , res);
    // }
    // cout<<ans;
    cout<<f2(0 , vec , w);
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