#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // notice that every leaf will require its own traversal
    // also that traversing to every leaf will also visit all the internal nodes
    //
    // this means that the minimum number of traversals would be to visit every leaf once
    // the goal is to maximize the number of potions we get within those traversals
    //
    // there is only a single potion at each time

    vector<int> pot(n);
    for (int i = 0; i < n; i++) cin >> pot[i];

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // notice that there is a single path that each node can take back to the root
    // just create a parent graph
    int leafs = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && g[i].size() == 1) {
            leafs++;
        }
    }

    vector<int> goals(n+1, 0);
    for (int i = 0; i < leafs; i++) {
        goals[pot[i]]++;
    }

    // work this out a bit like a max-flow problem
    // find the number of times we will visit each node
    // the times we can visit each subtree is based on the times we visit the root of the subtree
    int res = 0;
    vector<int> p(n+1);
    vector<int> v(n+1, 0); // max times we can pass though/visit this node
    auto dfs = [&](auto self, int i, int parent) -> void {
        p[i] = parent;
        if (i != 1 && g[i].size() == 1) {
            v[i] = 1;
        }

        for (int j: g[i]) {
            if (j == parent) {
                continue;
            }
            self(self, j, i);
            v[i] += v[j];
        }

        // topo sort end time, we will perform this at the leafs first
        res += min(v[i], goals[i]);
        v[i] -= min(v[i], goals[i]);
    };
    dfs(dfs, 1, 1);

    // // each traversal can pick up only at most one potion
    // // when a potion is at a leaf then just get it
    // // if a potion is at a internal node then try to get it
    // set<int> leafs;
    // for (int i = 1; i <= n; i++) {
    //     if (g[i].size() == 1) {
    //         leafs.insert(i);
    //     }
    // }

    // set<int> other;
    // int res = 0;
    // int leaf_n = leaf.size();
    // for (int i = 0; i < leaf_n; i++) { 
    //     if (leafs.count(pot[i])) {
    //         res++;
    //         leafs.erase(pot[i]);
    //     } else {
    //         other.insert(pot[i]);
    //     }
    // }

    // // using the remaining leafs try to pick up as many potions as possible
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
