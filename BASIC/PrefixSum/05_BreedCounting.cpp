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
    for(int i = 0 ; i < n; i++) cin>>vec[i];
    vector<int> v1(n,0);
    vector<int> v2(n,0);
    vector<int> v3(n,0);
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            if(vec[i] == 1) v1[i] = 1;
            else if(vec[i] == 2)v2[i] = 1;
            else v3[i] = 1;

        }else{
            if(vec[i] == 1) v1[i] = 1 + v1[i-1];
            else v1[i] += v1[i-1];
            if(vec[i] == 2) v2[i] = 1 + v2[i-1];
            else v2[i] += v2[i-1];
            if(vec[i] == 3) v3[i] = 1 + v3[i-1];
            else v3[i] += v3[i-1];
        }
    }
    while(q--){
        int l , r;
        cin>>l>>r;
        l--;
        r--;
        int f = 0;
        int s = 0;
        if(l > 0) f = v1[l-1];
        s = v1[r];
        cout<<s-f<<" ";

        f = 0; s = 0;
        if(l > 0) f = v2[l-1];
        s = v2[r];
        cout<<s-f<<" ";

        f = 0; s = 0;
        if(l > 0) f = v3[l-1];
        s = v3[r];
        cout<<s-f<<endl;
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}