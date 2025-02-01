#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

void solve() {
    int n, tar;
    cin >> n >> tar;
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;
        vec[i].second = i + 1;  // Store original indices
    }

    sort(vec.begin(), vec.end());  // Sort based on values

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = vec[i].first + vec[left].first + vec[right].first;

            if (sum == tar) {
                cout << vec[i].second << " " << vec[left].second << " " << vec[right].second;
                return;
            }
            (sum < tar) ? left++ : right--;
        }
    }
    cout << "IMPOSSIBLE";
}

int32_t main() {
    fast_io;
    solve();
    return 0;
}
