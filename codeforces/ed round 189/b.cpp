#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;

    // we can only perform operation at most once
    //
    // fix two violations
    // - even length: don't invert just reverse (aabb -> abab)
    // - odd length: invert and reverse (reverse doesn't matter)
    //
    // fix one violation
    // - smae as two violations but go to one end
    //
    //

    const int n = s.size();
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == s[i]) {
            res++;
        }
    }

    if (res <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
