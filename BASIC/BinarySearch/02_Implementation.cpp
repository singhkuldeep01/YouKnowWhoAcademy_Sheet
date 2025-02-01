#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (k--) {
        int x;
        cin >> x;
        auto it = upper_bound(arr.begin(), arr.end(), x);
        int index = (it - arr.begin()); 
        cout << index << "\n";
    }
}

int32_t main() {
    fast_io;
    solve();
    return 0;
}
