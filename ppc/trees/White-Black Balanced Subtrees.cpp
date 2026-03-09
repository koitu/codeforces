#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    int a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        g[a].push_back(i);
    }
    string c;
    cin >> c;

    int res = 0;
    vector<int> w(n+1, 0);
    vector<int> b(n+1, 0);
    const auto dfs = [&](auto self, int i, int p) -> void {
        if (c[i-1] == 'W') {
            b[i] = 1;
        } else {
            w[i] = 1;
        }

        for (int j: g[i]) {
            if (j == p) {
                continue;
            }
            self(self, j, i);
            b[i] += b[j];
            w[i] += w[j];
        }

        if (b[i] == w[i]) {
            res++;
        }
    };
    dfs(dfs, 1, 1);

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
