#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0);
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> vec(n), prefix(n);
    
    // Read input and compute prefix sum
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        prefix[i] = vec[i] + (i > 0 ? prefix[i - 1] : 0);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert 1-based to 0-based indexing

        // Compute sum from index a to b
        ll result = prefix[b] - (a > 0 ? prefix[a] : 0);
        cout << result << "\n";
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}
