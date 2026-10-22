#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;

    // three parts
    // - cycle finding: determine if it is possible first
    // - grouping: group up the cucumbers into
    // - counting: groups > 1 count as two since they can be reversed order matters so factorial then mutliply by twos

    // guaranteed that each unordered pair is distinct
    int u, v;
    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<bool> visited(n, false);
    vector<bool> done(n, false);

    auto dfs = [&](auto self, int p, int c) -> bool {
        if (done[c]) {
            return true;
        }
        if (visited[c]) {
            return false;
        }
        visited[c] = true;

        for (auto nxt: g[c]) {
            if (nxt == p) continue;
            if (self(self, c, nxt) == false) {
                return false;
            }
        }

        done[c] = true;
        return true;
    };

    int group1 = 0;
    int group2 = 0;
    for (int i = 0; i < n; i++) {
        // special!
        if (g[i].size() > 2) {
            cout << -1 << endl;
            return;
        }

        // cout << i << ": ";
        // for (int j = 0; j < n; j++) {
        //     cout << (done[j] ? 'x' : '.');
        // }
        // cout << endl;

        if (done[i]) {
            continue;
        }

        if (g[i].empty()) {
            group1++;
            continue;
        }

        if (dfs(dfs, i, i)) {
            group2++;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    // cout << endl << group1 << " " << group2 << endl;

    long long res = 1;
    const long long mod = 1e9 + 7;
    for (long long l = 1; l <= group1 + group2; l++) {
        if (l > group1) {
            res = (res * 2LL) % mod;
        }
        res = (res * l) % mod;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
