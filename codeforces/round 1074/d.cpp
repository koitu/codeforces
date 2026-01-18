#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, m, h;
    cin >> n >> m >> h;

    vector<long long> cur(n, 0);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long b, c;
    set<long long> valid; // the set of valid indices

    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        b--;

        if (!valid.count(b)) {
            cur[b] = a[b];
            valid.insert(b);
        }

        cur[b] += c;
        if (cur[b] > h) {
            valid.clear();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (valid.count(i) ? cur[i] : a[i]) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
