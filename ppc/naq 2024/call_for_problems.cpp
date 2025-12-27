#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int res = 0;
    int j;
    for (int i = 0; i < n; i++) {
        cin >> j;
        if (j % 2 == 1) {
            res++;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
