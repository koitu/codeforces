#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<set<int>> g(n + 1);
    // get the vertices with the max edges
    // then get another vertex with max edges (notice that they ccan shared up to 1 edge)
    //
    // goal: find two vertices such that their set of edges are maximal
    // notice that the shared edges between two vertices is at most 1
    //
    // can we always pick the maximal vertex as our first choice?
    // imagine 3 maximal vertices in a row then we would be unluck to pick the one in the middle
    // however notice that since this is a tree if we pick 3 maximal vertices than at least one pair should be the best

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;

        g[a].insert(b);
        g[b].insert(a);
    }

    if (n <= 3) {
        cout << n - 2 << endl;
        return;
    }

    vector<pair<int, int>> best;
    for (int i = 1; i <= n; i++) {
        best.emplace_back(g[i].size(), i);
    }
    sort(best.begin(), best.end());
    reverse(best.begin(), best.end());

    // notice that n > 3
    // int x = best[0].second;
    // int y = best[1].second;
    // int z = best[2].second;
    // cout << x << " " << y << " " << z << endl;

    // for (int j: g[x]) {
    //     cout << j << endl;
    // }

    // the first cut will create "edges" components
    // on these components we perform another cut
    // - we cannot cut an already cut edge

    // // terrible...
    // int res = 0;
    // int m = min(100, (int)best.size());
    // for (int i = 0; i < m; i++) {
    //     for (int j = i + 1; j < m; j++) {
    //         int x = best[i].second;
    //         int y = best[j].second;

    //         int cur = g[x].size() - 1;
    //         for (int k: g[y]) {
    //             if (x != k) {
    //                 cur++;
    //             }
    //         }

    //         res = max(res, cur);
    //     }
    // }

    // try two different nodes: to prevent worst case of 3 maximal attached
    int res = 0;
    for (int i = 0; i < 2; i++) {
        int x = best[i].second;
        set<int> save(g[x]);

        for (int y: save) {
            g[y].erase(x);
        }

        int best = 0;
        for (int y = 1; y <= n; y++) {
            if (y == x) {
                continue;
            }

            best = max(best, (int)g[y].size());
        }

        for (int y: save) {
            g[y].insert(x);
        }

        res = max(res, best + (int)g[x].size() - 1);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
