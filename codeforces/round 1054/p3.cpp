#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n, k;
    cin >> n >> k;
    // Your code here
    // in one op we can set any a[i] to [0, n]
    // find the min ops to satisfy MEX(a) = k
    // MEX(a) is the smallest non-negative int that does appear among a

    // how many operations do be need to move all k's and supply all the values to it's left
    int on = 0;
    vector<bool> sup(k, false);

    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;

        if (c < k) {
            // good support
            sup[c] = true;
        }
        if (c == k) {
            // most be moved
            on++;
        }
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        if (!sup[i]) {
            res++;
        }
    }

    // get the max of: moving to fill in sup or moving things on k
    cout << max(res, on) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
