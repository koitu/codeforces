#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // tree of n nodes
    // matching is a set of edges where each node is an endpoint of at most one edge
    // what is the max number of edges in a matching

    // can we just greedy pick?
    // pick 1 then try to not pick 1
    // what which edge do we pick?

    map<int, set<int>> g;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    // idea: take a leaf and remove the node it is connected to (then find another leaf)
    // consider the bamboo: tree with n nodes and only two leafs
    // consider the star: tree with nodes and only a single node with >1 degree
    // rather than iterating over every node each time keep track of the leafs

    set<int> leafs;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            leafs.insert(i);
        }
    }

    int res = 0;
    while (!leafs.empty()) {
        int i = *leafs.begin();
        leafs.erase(i);
        if (g[i].size() != 1) {
            continue;
        }

        res++;

        int j = *g[i].begin();
        for (int o: g[j]) {
            g[o].erase(j);
            if (g[o].size() == 1) {
                leafs.insert(o);
            }
        }
        g.erase(i);
        g.erase(j);
    }

    cout << res << endl;
}

