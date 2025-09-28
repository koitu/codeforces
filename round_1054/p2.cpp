#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    int c;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c;
        v[i] = c;
    }

    sort(v.begin(), v.end());

    int res = 0;
    for (int i = 0; i < n; i += 2) {
        res = max(res, v[i+1] - v[i]);
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
