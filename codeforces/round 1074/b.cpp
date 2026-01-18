#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int best = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        best = max(best, a);
    }

    cout << best * n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
