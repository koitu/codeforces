#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 2; i <= n; i++) {
        cin >> a;

        // we just need one way because we know that 1 is the root
        g[a].push_back(i);
    }

    vector<pair<int, int>> res;
    map<int, vector<pair<int, int>>> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        q[a].emplace_back(b, i);
    }

    // backtracking
    vector<int> prev;
    auto dfs = [&](auto self, int i) -> void {
        int l = prev.size();
        for (auto [u, idx]: q[i]) {
            int cur = l - u;
            res.emplace_back(idx, cur < 0 ? -1 : prev[cur]);
        }

        prev.push_back(i);
        for (int j: g[i]) {
            self(self, j);
        }
        prev.pop_back();
    };
    dfs(dfs, 1);

    sort(res.begin(), res.end());
    for (int i = 0; i < m; i++) {
        cout << res[i].second << endl;
    }
}

