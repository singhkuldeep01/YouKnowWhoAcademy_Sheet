#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

const int MAXN = 1e6 + 1;
vector<int> divisors(MAXN, 0);

void preprocess() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << divisors[__gcd(a, b)] << '\n';
}

int32_t main() {
    fast_io;
    preprocess();

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
