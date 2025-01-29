#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , q;
    cin>>n>>q;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++) cin>>vec[i];
    for(int i = 1 ; i < n ; i++) vec[i] += vec[i-1];
    while (q--){    
        int l , r , k;
        cin>>l>>r>>k;
        int len = r-l+1;
        int f = 0;
        int s = 0;
        r--;
        l--;
        if(l > 0) f = vec[l-1];
        s = vec[r];
        int currSum = s - f;
        int totalSum = vec[n-1];
        totalSum -= currSum;
        totalSum += (k*len);
        if((totalSum & 1) == 0)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
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
    cin>>t;
    while(t--) solve();
    return 0;
}