#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int a, b;
    cin >> a;
    int res = 0;

    for (int i = 1; i < n; i++) {
        cin >> b;
        if (b >= a) {
            a = b;
        } else {
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
