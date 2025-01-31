#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , m;
    cin>>n>>m;
    multiset<int> tic;
    vector<int> cus(m);
    for(int i = 0 ; i  < n ; i++) {
        int ele;
        cin>>ele;
        tic.insert(ele);
    }
    for(int i = 0 ; i  < m ; i++) cin>>cus[i];
    for(int i = 0 ; i < m ; i++){
        auto it = tic.lower_bound(cus[i]);
        if(*it == cus[i]){
            cout<<*it<<" ";
            tic.erase(it);
        }else{
            if(it != tic.begin()){
                it = prev(it , 1);
                cout<<*it<<" ";
                tic.erase(it);
            }else cout<<-1<<" ";
        }
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
    //cin>>t;
    while(t--) solve();
    return 0;
}