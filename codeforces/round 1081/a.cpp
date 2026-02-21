#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    // just brute force
    int best = 0;
    for (int offset = 0; offset < n; offset++) {
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (s[(i + offset) % n] != s[(i + 1 + offset) % n]) {
                cur++;
            }
        }

        best = max(best, cur);
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
