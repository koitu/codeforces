#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    map<int, set<int>> g;
    vector<vector<int>> g_save(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        g_save[a].push_back(b);
        g_save[b].push_back(a);
    }

    // find the dist from each node to its furthest node
    // idea: find the centroids and their distance to the furthest node
    //  - then using dfs form the centroids and add distance based on height

    int res = 0;
    queue<int> cur;
    queue<int> nxt;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            cur.push(i);
        }
    }

    while (!cur.empty()) {
        if (g.size() <= 2) {
            break;
        }
        res++;

        while (!cur.empty()) {
            int i = cur.front(); cur.pop();

            for (int j: g[i]) {
                g[j].erase(i);
                if (g[j].size() == 1) {
                    nxt.push(j);
                }
            }

            g.erase(i);
        }

        swap(cur, nxt);
    }

    vector<int> dist(n+1, 0);
    auto dfs = [&](auto self, int i, int p, int h) -> void {
        dist[i] = max(dist[i], res + h);

        for (int j: g_save[i]) {
            if (j == p) {
                continue;
            }
            self(self, j, i, h+1);
        }
    };
    // notice that if there are two centroids we recurse twice but due to max in dist we get the correct result
    for (const auto& [i, _]: g) {
        dfs(dfs, i, i, 0);
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

