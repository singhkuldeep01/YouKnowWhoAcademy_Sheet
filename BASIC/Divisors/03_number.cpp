#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , k;
    cin>>n>>k;
    int cnt = 0;
    if(n != 1) cnt = 2;
    else cnt = 1;
    vector<int> divisor;
    // cout<<sqrt(12);
    divisor.push_back(1);
    divisor.push_back(n);
    int len = sqrt(n);
    for(int i = 2 ; i <= len ; i++){
        if(n % i == 0){
            cnt++;
            divisor.push_back(i);
            if(i != n/i){
                cnt++;
                divisor.push_back(n/i);
            }
        }
    }
    sort(divisor.begin() , divisor.end());
    if(cnt < k)cout<<-1<<endl;
    else cout<< divisor[k-1]<<endl;
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