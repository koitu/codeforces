#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < 2*n - 1; i++) {
        cout << "1 ";
    }
    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
