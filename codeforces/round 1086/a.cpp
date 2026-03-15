#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    map<int, int> m;
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            m[a]++;
        }
    }

    bool valid = true;
    int thres = (n * n) - n;
    for (auto [_, c]: m) {
        if (c > thres) {
            valid = false;
            break;
        }
    }

    if (valid) {
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
