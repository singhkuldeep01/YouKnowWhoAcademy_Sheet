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
    string s;
    cin>>s;
    vector<int> divisors(n+1, 0);
    // int ans = 0;
    for(int i = 1; i <= n ; i++){
        if(s[i-1] == '0'){
            for(int j = i ; j <= n ; j += i){
                if(s[j-1] == '0'){
                    // cout<<i<<" "<<j<<endl;
                    if(divisors[j] == 0)
                    divisors[j] = i;
                }
                else break;
            }
        }
    }
    int ans = accumulate(divisors.begin(), divisors.end() , 0LL);
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