#include <bits/stdc++.h>
using namespace std;


void solve() {
    int x, y;
    cin >> x >> y;

    // bounds are too larger to prefrom dp

    // idea: notice that we can only move right on the x coordinate
    // we want to break down (x, y) in to (2, 1) (3, 0) (4, -1)
    //
    // if we combine (2, 1) and (4, -1) we get (6, 0) which is worse than (3, 0)
    // since (2, 1) and (4, -1) ALWAYS cancel out this way we have two choices:
    // - use (2, 1) and (3, 0)
    // - use (4, -1) and (3, 0)
    // if we cannot make (x, y) in either way then we cannnot make (x, y)

    if (y > 0) {
        x -= y * 2;
        y = 0;
    }
    if (y < 0) {
        x += y * 4;
        y = 0;
    }

    if (x >= 0 && (x % 3 == 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
