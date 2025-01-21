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

int countDigits(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n /= 10;
    }
    return cnt;
}
void solve() {
    int n;
    cin>>n;
    int digits = countDigits(n);
    digits--;
    vector<int> ans;
    bool first = true;
    for(int i = digits ; i >= 0 ; i--){
        int num = n / pow(10,i);
        num = num % 10;
        if(num == 0 && first){
            first = false;
            continue;
        }
        ans.push_back(num);
    }
    n = 0;
    for(auto ele : ans){
        n = n*10 + ele;
    }
    cout<<n;
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