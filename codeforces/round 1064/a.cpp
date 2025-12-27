#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char c = s[n - 1];
    int res = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] != c) {
            res++;
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
