#include <bits/stdc++.h>
using namespace std;


void solve() {
    int a, b;
    cin >> a >> b;

    int g = a ^ b;
    vector<int> res;
    int c = 1;
    while (g > 0) {
        if (g & 1) {
            res.push_back(c);
        }
        c <<= 1;
        g >>= 1;
    }

    bool valid = true;
    int aa = a;
    for (int i: res) {
        if (i > aa) {
            valid = false;
            break;
        }
        aa ^= i;
    }

    if (valid) {
        cout << res.size() << endl;
        for (int i: res) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
