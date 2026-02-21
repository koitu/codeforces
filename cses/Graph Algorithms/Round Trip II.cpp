#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // round trip that begins at a city goes through one or more other cities then finally returns
    int a, b;
    map<int, set<int>> graph;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].insert(b);
    }

    // dfs: i.e. topo search
    // then find the cycle
    vector<bool> visited(n+1, false);
    vector<bool> done(n+1, false);
    vector<int> pred(n+1, 0);
    auto dfs = [&](auto self, int pre, int cur) -> bool {
        // cycle not found
        if (done[cur]) {
            return true;
        }

        // cycle found
        if (visited[cur]) {
            // pred[cur] = pre;
            return false;
        }
        visited[cur] = true;

        for (int nxt: graph[cur]) {
            if (!self(self, cur, nxt)) {
                pred[cur] = nxt;
                return false;
            }
        }

        done[cur] = true;
        return true;
    };

    set<int> s;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!dfs(dfs, 0, i)) {
            // cout << endl << i << endl;
            // for (int j = 1; j <= n; j++) {
            //     cout << j << " " << pred[j] << endl;
            // }
            // cout << endl;

            s.insert(i);
            int cur = pred[i];
            while (!s.count(cur)) {
                s.insert(cur);
                cur = pred[cur];
            }

            int goal = cur;
            res.push_back(cur);
            cur = pred[cur];
            while (cur != goal) {
                res.push_back(cur);
                cur = pred[cur];
            }
            res.push_back(cur);

            cout << res.size() << endl;
            for (int c: res) {
                cout << c << " ";
            }
            cout << endl;

            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

