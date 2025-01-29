#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int sum = 1;
    int n;
    cin>>n;
    if(n == 1) {
        cout<< 0<<endl;
        return;
    }
    int sq = sqrt(n);
    for(int i = 2 ; i <= sq ; i++){
        if(n % i == 0){
            sum += i;
            if(i != n/i){
                sum += (n/i);
            }
        }
    }
    cout<<sum<<endl;
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