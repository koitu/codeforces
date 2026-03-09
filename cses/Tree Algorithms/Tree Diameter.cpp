#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    map<int, set<int>> g;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    // degenerate case where there cannot be a node with degree > 1
    // if (n <= 2) {
    //     cout << n << endl;
    // }

    // // find any node with degree > 1
    // int root = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (g[i].size() > 1) {
    //         root = i;
    //         break;
    //     }
    // }

    // // wat
    // if (root == 0) {
    //     return 1;
    // }

    // vector<int> d(n+1, 1);
    // auto dfs = [&](auto self, int i, int p) -> void {
    //     int best = 1;

    //     for (int j: g[i]) {
    //         if (j == p) {
    //             continue;
    //         }
    //         self(self, j, i);
    //         best = max(best, d[j]);
    //     }

    //     d[i] = best + 1;
    // };
    // dfs(dfs, root, 0);

    // above find the longest path that passes through root!
    // instead we want to trim the leafs of the tree until there are one or two points left
    // https://leetcode.com/problems/minimum-height-trees/description/

    queue<int> cur;
    queue<int> nxt;
    int res = 0;
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
            // cout << i << endl;

            for (int j: g[i]) {
                g[j].erase(i);
                if (g[j].size() == 1) {
                    nxt.push(j);
                }
            }

            g.erase(i);
        }

        swap(nxt, cur);
    }

    // res is now the number of times we reomve leafs until we get our centroid of 1 or 2 nodes
    // note that we want to get longest distance from one node to another (which is why is sub 1)
    cout << (res*2) + g.size() - 1 << endl;
}

