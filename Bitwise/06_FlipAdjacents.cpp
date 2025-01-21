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

void solve() {
    int n;
    cin>>n;
    for(int i = 1 ; i < 32 ; i+=2){
        int bit1 = (n >> i) & 1;
        int bit2 = (n >> (i-1)) & 1;
        if(bit1 != bit2){
            n ^= (1 << i);
            n ^= (1 << (i-1));
        }
    }
    n = n & 0xFFFFFFFF;
    cout<<n<<" ";
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}