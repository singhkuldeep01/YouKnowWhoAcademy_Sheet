#include <stdio.h>

#define MOD 1000000007

// Function to compute gcd
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// Function to compute lcm
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void solve() {
    long long a, k;
    scanf("%lld %lld", &a, &k);

    long long ans1 = 0;
    long long ans2 = 0;
    long long ans3 = 0;

    // Loop to check the bitwise operations for all pairs
    for (long long i = 1; i <= a; i++) {
        for (long long j = i + 1; j <= a; j++) {
            if (((i & j) < k) && ans1 < (i & j)) {
                ans1 = i & j;
            }
            if (((i | j) < k) && ans2 < (i | j)) {
                ans2 = i | j;
            }
            if (((i ^ j) < k) && ans3 < (i ^ j)) {
                ans3 = i ^ j;
            }
        }
    }

    printf("%lld\n", ans1);
    printf("%lld\n", ans2);
    printf("%lld\n", ans3);
}

int main() {
    long long t = 1;
    // If multiple test cases are needed, uncomment below line and replace `t` accordingly.
    // scanf("%lld", &t);

    while (t--) solve();
    return 0;
}
