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
    vector<priority_queue<int>> pq(n);
    while(q--){
        int type , number , value;
        cin>>type>>number;
        if(type == 0){ // push
            int value;
            cin>>value;
            pq[number].push(value);
        }else if(type == 1){ // top
            if(pq[number].size())
                cout<<pq[number].top()<<endl;
        }else{ // pop
            if(pq[number].size())
                pq[number].pop();
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