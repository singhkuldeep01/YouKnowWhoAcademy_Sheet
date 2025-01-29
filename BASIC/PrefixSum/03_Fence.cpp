#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    for(int i = 1 ; i < n ; i++){
        v[i] += v[i-1];
    }
    int i = 0;
    int j = i+k-1;
    int sum = v[j];
    int index = 0;
    j++;
    for(j ; j < n ;j++){
        int curr = v[j] - v[i];
        if(curr < sum){
            index = i+1;
            sum = curr;
        }
        i++;
    }
    cout<<index+1<<endl;
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