#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(0);cin.tie(0);

const int MAX_N = 1e6 + 1;
int divisor_count[MAX_N];

void precompute_divisors() {
    for (int i = 1; i < MAX_N; i++) {
        for (int j = i; j < MAX_N; j += i) {
            divisor_count[j]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << divisor_count[n] << endl;
}

int32_t main() {
    fast_io;
    precompute_divisors();
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
