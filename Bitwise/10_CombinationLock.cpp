#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int power(int b, int p, int m) {
    if (p == 0) return 1;
    if (p == 1) return b;
    int res = power(b, p / 2, m);
    return (p % 2 == 0) ? (res * res) % m : (((res * res) % m) * b) % m;
}

// vector<vector<int>> dp;

// bool helper(int i, vector<int>& vec, int degree) {
//     degree = (degree % 360);
//     if (i == vec.size()) {
//         return (degree == 0);
//     }
//     if (dp[i][degree] != -1) return dp[i][degree];

//     bool ans = helper(i + 1, vec, (degree + vec[i] )) || 
//                helper(i + 1, vec, (degree - vec[i] + 360));

//     return dp[i][degree] = ans;
// }

// bool bottomUp(vector<int>& vec){
//     int n = vec.size();
//     vector<int> prev(361, false);
//     prev[0] = true;
//     vector<int> curr(361, false);
//     for(int i = n-1 ; i >= 0 ; i--){
//         for(int j = 0 ; j < 360 ;j++){
//             bool ans = prev[(j + vec[i])%360];
//             ans |= prev[(j - vec[i] + 360)%360];
//             curr[j] = ans;
//         }
//         prev = curr;
//     }
//     return curr[0];
// }

bool bitmasking(vector<int>&vec){
    int n = vec.size();
    int subSets = 1<<n;
    for(int i = 0 ; i < subSets ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            // if 1 clockwise else anti-clockwise
            if(i & (1<<j)){
                sum += vec[j];
            }else{
                sum -= vec[j];
            }
        }
        if(sum % 360 == 0) return true;
    }
    return false;

}

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    if(bitmasking(vec)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    // dp.assign(n + 1, vector<int>(361, false));

    // cout << (helper(0, vec, 0) ? "YES" : "NO") << endl;
    // cout << (bottomUp(vec) ? "YES" : "NO") << endl;
}

int32_t main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
