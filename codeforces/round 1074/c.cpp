#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // find the longest seq of consec values
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int best = 0;
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            continue;
        } else if (a[i-1] + 1 == a[i]) {
            cur++;
        } else {
            best = max(best, cur);
            cur = 0;
        }
    }
    best = max(best, cur);

    cout << best + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
