#include <bits/stdc++.h>
using namespace std;


void solve() {
    int l, a, b;
    cin >> l >> a >> b;

    int mx = a;
    int cr = a;
    for (int i = 1; i <= l; i++) {
        cr = (cr + b) % l;
        mx = max(mx, cr);
    }

    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
