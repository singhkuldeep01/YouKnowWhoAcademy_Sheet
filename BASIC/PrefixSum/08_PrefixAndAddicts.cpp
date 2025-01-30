#include <bits/stdc++.h>
#include <cmath>  // Include cmath for ceil function
using namespace std;

#define int long long
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }

    if (k == 1) {
        cout << "YES" << endl;
        return;
    }

    vector<int> a(k);
    
    for (int i = 1; i < k; i++) {
        a[i] = s[i] - s[i - 1];
    }

    for (int i = 2; i < k; i++) {
        if (a[i] < a[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    if (ceil((double)s[0] / (double)(n - k + 1)) > a[1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
