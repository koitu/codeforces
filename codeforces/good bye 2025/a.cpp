#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;

    const int n = s.size();
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y') {
            y++;
        }
    }

    if (y >= 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
