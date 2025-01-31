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
    multiset<int> ms;
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin>>ele;
        ms.insert(ele);
    }
    while(q--){
        int type , ele;
        cin>>type;
        if(type == 0){
            cin>>ele;
            ms.insert(ele);
        }else if(type == 1){
            auto first = ms.begin();
            if(first != ms.end()){
                cout<<*first<<endl;
                ms.erase(first);
            }
        }else{
            auto last = prev(ms.end());
            if(last != ms.end()){
                cout<<*last<<endl;
                ms.erase(last);
            }
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