#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    int c;
    int res = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 0) {
            res++;
        }
        if (c == -1) {
            neg++;
        }
    }

    if (neg % 2 == 1) {
        res += 2;
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
