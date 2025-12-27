#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // idx of the best most nearby value (a for left and c for right)
    // note that 0 and n-1 idx are undefined
    vector<int> a(n);
    vector<int> c(n);

    int a_idx = 0;
    int a_val = b[0];
    int c_idx = n - 1;
    int c_val = b[n - 1];
    for (int i = 1; i < n; i++) {
        a[i] = a_idx;
        c[n - 1 - i] = c_idx;

        // at each index we reduce the values of all previous by one
        if (b[i] + i > a_val) {
            a_idx = i;
            a_val = b[i] + i;
        }
        if (b[n - i - 1] + i > c_val) {
            c_idx = n - i - 1;
            c_val = b[n - i - 1] + i;
        }
    }

    int res = 0;
    for (int i = 1; i < n-1; i++) {
        res = max(res, b[a[i]] + b[i] + b[c[i]] - (c[i] - a[i]));
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
