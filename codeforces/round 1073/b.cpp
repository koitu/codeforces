#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // idea: something about 0 and 1
    // - for the side without zero the MEX is always 0
    // - case 1: if there is no zeros -> always NO
    // - case 2: if there is one zero -> always YES (place that zero at the beginning, then prefix allways >0 and suffix =0)
    // - case 3: if there is >1 zero -> YES if there is a one otherwise NO

    // sorted array is a solution  iff  there is a MEX reordering
    // 0...0 1...1 [ everything else ]
    // - inside zeros: left is 1 and right is > 1
    // - between zeros and ones: left is 1 and right is 0
    // - otherwise: left is 2 and right is 0

    int zeros = 0;
    int ones = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) zeros++;
        if (a == 1) ones++;
    }

    if (zeros == 0) {
        cout << "NO" << endl;

    } else if (zeros == 1) {
        cout << "YES" << endl;

    } else {
        cout << (ones > 0 ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
