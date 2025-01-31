#include <bits/stdc++.h>
using namespace std;


void solve() {
    set<int> st;
    int q ;
    cin>>q;
    while(q--){
        int type , ele;
        cin>>type>>ele;
        if(type == 1){
            st.insert(ele);
        }else if(type == 2){
            st.erase(ele);
        }else{
            if(st.find(ele) != st.end()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}