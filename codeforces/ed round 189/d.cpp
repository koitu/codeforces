#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, x;
    cin >> n >> x;

    // have seq 1, ..., n

    // only consider segments that pass through x

    // how many segments XOR to 0

    // main issue: n is extremely large
    // - cannot iterate over any part of n
    // - need to find solution without counting

    // consider the XOR of n and n+1
    // maybe this can tell us something about the structure of the problem
    // 15 ^ 16 = 31
    // 16 ^ 17 = 1
    //
    // testing out segments of length 1, 2, 3, 4, 5, 6, 7 there is a strange structure
    // - only get zeros at segments of length 4, 7, 8 (but only sometimes)
    // - need to split problem into even and odd length segments
    //  - then consider what shifting the segment over does

    // I can't prove it but segments of 1 to 2^n - 1 XOR to 0
    // also for segments of length 2^n as long as they start with some even number they XOR to 0
    //
    // I hope these are all the cases when we XOR to 0...

    long long res = 0;
    long long cur = 1;
    while (cur <= n) {
        if (x <= cur) {
            res++;
        }
        cur <<= 1;
    }

    const long long MOD = 998244353;
    for (long long i = 4; i <= n; i <<= 1) {
        // find the number of times we can tile i while remaining within 1 and n

        // if x is odd then plus one to bottom and minus one to top for the decreased reach
        long long bot = max(1LL, x - i);
        long long top = min(n, x + i);

        // cout << bot << " " << top << endl;

        res += (top - bot + 1LL - i) / 2;
        res %= MOD;
    }

    // dang I choked this so hard...
    // coundn't figure out how to count the number of ranges of size i that contain x and are within 1 to n

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
