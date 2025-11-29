#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, y, r;
    cin >> n >> y >> r;
    r += y/2;

    cout << min(n, r) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
