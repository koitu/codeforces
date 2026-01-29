#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());

    // when the array is already sorted then output -1
    int mx = a[0];
    int mn = a[0];
    int sorted = true;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);

        if (a[i] != b[i]) {
            sorted = false;
        }
    }
    if (sorted) {
        cout << -1 << endl;
        return;
    }

    // otherwise ???
    // I expect to need some kind of binary search...
    // but might be possible to do without
    //
    // idea: like solving a rubics cube
    // to move some value to its correct location we can first swap it with the farthest value

    // I think this might work...
    // using the distance from each unsorted value to the largest or smallest value
    // cout << mn << " " << mx << endl;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            res = min(res, max(mx - a[i], a[i] - mn));
        }
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
