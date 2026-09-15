#include <bits/stdc++.h>
using namespace std;


void solve() {
    vector<int> a;
    int b;
    for (int i = 0; i < 3; i++) {
        cin >> b;
        a.push_back(b);
    }

    int mx = a[0];
    int mn = a[0];
    for (int i = 0; i < 3; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    cout << mx - mn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
