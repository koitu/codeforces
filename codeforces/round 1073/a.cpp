#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<bool> color(n + 1);
    vector<int> a(n);
    bool cur = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        color[a[i]] = cur;
        cur = !cur;
    }

    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (color[a[i-1]] == color[a[i]]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
