#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // remember that in a tree if there is a path between two nodes
    // that must be the ONLY path

    // idea: for each node consider all the nodes that point to it as ancestors
    // - try to construct a tree with such ancestors, then find a node that every ancestor can reach and connect it to the current node
    // - connect all ancestors to the current node then only keep the longest path?
    //   - must ensure that is only a single longest path, otherwise it is invalid (not a tree since two different nodes are connected to it
    //

    // idea: find the root
    //  - notice that every node must be reachable from the root, otherwise fail
    //  - recurse and construct a subtree on any child
    //  - if we hit a previous constructed subtree then append it (i.e. add an edge and remove the edge from root)
    //  - at the end check for tree structure (no cycles, no repeat visits, full viists)

    // finding the root: start at any point then go back until we can't anymore, if we repeat visits then loop fail
    string s;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j] == '1';
        }
    }
    for (int i = 0; i < n; i++) {
        if (!g[i][i]) {
            cout << "NO" << endl;
        }
    }

    // vector<bool> visited(n, false);
    // int root = 0;
    // while (true) {
    //     if (visited[root]) {
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     visited[root] = true;

    //     bool path = false;
    //     for (int i = 0; i < n; i++) {
    //         if (g[i][root]) {
    //             root = i;
    //             path = true;
    //             break;
    //         }
    //     }

    //     if (!path) {
    //         break;
    //     }
    // }

    // // idea: we can only steal from root?
    // vector<set<int>> g(n);
    // vector<bool> done(n, false);
    // visited = vector<bool>(n, false);

    // idea: a node can only be a child of another node when the binary string is a subset of the parent
    // - starting from some leaf find all the parents
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
