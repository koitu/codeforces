#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // topo sort
    int a, b;
    map<int, set<int>> graph;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].insert(b);
    }

    int time = 0;
    vector<bool> done(n + 1, false);
    vector<bool> visited(n + 1, false);
    vector<int> done_time(n + 1);
    auto dfs = [&](auto self, int i) -> bool {
        if (done[i]) {
            return true;
        }
        if (visited[i]) {
            // found cycle
            return false;
        }
        visited[i] = true;

        for (int j: graph[i]) {
            if (!self(self, j)) {
                return false;
            }
        }

        done_time[i] = time++;
        done[i] = true;
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if (!dfs(dfs, i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    vector<pair<int, int>> vals;
    for (int i = 1; i <= n; i++) {
        // cout << done_time[i] << endl;
        vals.emplace_back(done_time[i], i);
    }
    sort(vals.begin(), vals.end(), greater<pair<int, int>>());
    for (auto [_, r]: vals) {
        cout << r << " ";
    }
    cout << endl;
}

