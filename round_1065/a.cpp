#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> res(n+1, 0);
    for (int i = 0; i <= n; i += 2) {
        res[i] = 1;
    }
    for (int i = 4; i <= n; i++) {
        res[i] += res[i-4];
    }
    cout << res[n] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
