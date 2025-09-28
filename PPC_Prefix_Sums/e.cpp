#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // rearrange
    // sum(ai, aj) = j - i + 1
    // p[r] - p[l] = r - l
    // p[r] - r = p[l] - l
    // now count pairs (l, r) s.t. l < r
    //
    // map that stores p[i] - 1
    // ans uses choose
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
