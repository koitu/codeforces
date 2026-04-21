#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long x, y;
    cin >> x >> y;

    // y > x
    // y % x == 0
    //
    // find z such that x < z < y
    // z % x == 0
    // z % y != 0

    // y is a multiple of x

    long long yx = y / x;
    long long zx = yx - 1; // best choice if we want to avoid z % y == 0?

    if (zx == 1 || yx % zx == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
