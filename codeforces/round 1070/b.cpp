#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<bool> a(n);
    char b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a[i] = (b == '1');
    }

    // find the longest part of all zeros
    // as we need at least this many shifts of s to make it completely 1s
    // we don't need more than this because each time we take the fresh string
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int cur = 0;

        while (i < n && !a[i]) {
            cur++;
            i++;
        }

        c.push_back(cur);
    }

    // loop c.size() > 1 since at least one 1
    if (!a[0] && !a[n-1]) {
        c[0] += c.back(); c.pop_back();
    }

    int res = 0;
    for (int d: c) {
        res = max(res, d);
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
