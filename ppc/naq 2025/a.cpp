#include <bits/stdc++.h>
using namespace std;


void solve() {
    int r, g, b; // values needed
    cin >> r >> g >> b;

    int cr, cg, cb; // currently has
    cin >> cr >> cg >> cb;

    int crg, cgb; // available to buy
    cin >> crg >> cgb;

    // first fill r and b with available to buy
    // then fill g
    
    r = max(r - cr, 0);
    g = max(g - cg, 0);
    b = max(b - cb, 0);

    int res = 0;
    if (r > crg || b > cgb) {
        cout << -1 << endl;
        return;
    }
    res = r + b;
    crg -= r;
    cgb -= b;

    if (g > crg + cgb) {
        cout << -1 << endl;
        return;
    }
    res += g;

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
