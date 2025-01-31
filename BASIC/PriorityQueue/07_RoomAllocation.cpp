#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
#define pp pair<int,int>
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
struct cmp{    
    bool operator()(const vector<int>&a , const vector<int>&b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }else{
            return a[1] < b[1];
        }
    }
};

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> vec(n , vector<int> (3));
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i][0]>>vec[i][1];
        vec[i][2] = i;
    }
    sort(vec.begin() , vec.end() , cmp());
    priority_queue<pp,vector<pp>, greater<pp>> customer;
    priority_queue<int,vector<int>, greater<int>> rooms;
    for(int i = 1 ; i <= n ; i++) rooms.push(i);
    int maxRooms = 0;
    vector<int> ans(n,0);
    for(int i = 0 ; i < n ; i++){
        while(customer.size() && customer.top().first < vec[i][0]){
            rooms.push(customer.top().second);
            customer.pop();
        }
        customer.push({vec[i][1] , rooms.top()});
        ans[i] = rooms.top();
        rooms.pop();
        maxRooms = max(maxRooms , (int)customer.size());
    }
    cout<<maxRooms<<endl;
    vector<int> temp(n);
    for(int i = 0 ; i < n ; i++){
        temp[vec[i][2]] = ans[i];
    }
    for(int i = 0 ; i < n ; i++) cout<<temp[i]<<" ";

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