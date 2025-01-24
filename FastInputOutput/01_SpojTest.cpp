#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main() {
    fast_io; // Enable fast I/O

    int N;
    cin >> N; // Read number of test cases

    while (N--) {
        int a, b;
        cin >> a >> b;
        cout << (a * b) << '\n'; // Print result efficiently
    }

    return 0;
}
