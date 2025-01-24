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

void solve() {
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int subSets = 1 << n;
    int sum = accumulate(vec.begin() , vec.end() , 0);
    int ans = INT_MAX;
    for(int mask = 0 ; mask < subSets ; mask++){
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0 ; i< n ; i++){
            if(mask & (1<<i)){
                sum1 += vec[i];
            }else{
                sum2 += vec[i];
            }
        }
        ans = min(ans , abs(sum1 - sum2));
    }
    cout<<ans<<" ";
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