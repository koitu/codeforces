#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // create a bipartite matching
    // just use greedy
    // if there is a pair within the same side then we are ded

    // want just want to find a augmenting path through dfs
    int a, b;
    map<int, set<int>> g;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b) {
            continue;
        }

        g[a].insert(b);
        g[b].insert(a);
    }

    vector<int> res(n + 1, 0);
    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        if (res[i] != 0) {
            continue;
        }
        s.emplace(i, 2);

        // each time we completely visit the connected component
        // so we can always start at 1 again
        while (!s.empty()) {
            auto [c, p] = s.top(); s.pop();

            if (res[c] == 0) {
                res[c] = (p != 1 ? 1 : 2);

                // only branch off when we have not visited this before
                for (auto nxt: g[c]) {
                    s.emplace(nxt, res[c]);
                }

            } else if (res[c] == p) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

