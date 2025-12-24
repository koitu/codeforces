#include <bits/stdc++.h>
using namespace std;


void solve() {
    int k, x;
    cin >> k >> x;

    // s uses only first k lowercase letters
    // for every pair of letters such that (j - i) is divisible by x the letters are different
    //
    // find the smallest n such that no valid string of length n exists

    cout << (k * x) + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
