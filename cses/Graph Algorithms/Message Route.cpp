#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // bfs
    map<int, set<int>> g;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b) {
            continue;
        }

        g[a].insert(b);
        g[b].insert(a);
    }

    vector<int> prev(n+1, INT_MAX);

    // cur node, prev node, dist
    queue<pair<int, int>> q;
    q.emplace(1, 1);

    while (!q.empty()) {
        auto [v, p] = q.front(); q.pop();
        if (prev[v] != INT_MAX) {
            continue;
        }
        prev[v] = p;

        for (auto u: g[v]) {
            q.emplace(u, v);
        }
    }

    //for (int i = 1; i <= n; i++) {
    //    cout << prev[i] << endl;
    //}
    if (prev[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> res;
    res.push_back(n);
    int p = prev[n];
    while (p != 1) {
        res.push_back(p);
        p = prev[p];
    }
    res.push_back(1);

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

