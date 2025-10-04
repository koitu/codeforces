#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    int q, c;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> c;
        cout << upper_bound(x.begin(), x.end(), c) - x.begin() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

//    int t;
//    cin >> t;
//    while (t--) solve();

    solve();
}
