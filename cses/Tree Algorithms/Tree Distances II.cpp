#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // idea: divide and conquor
    // split the tree into parts based on the current node and find the sum of distances to this current node
    // then recurse into each each part and add the contribution of getting from each node to nodes in every other part (scaling is linear with height and number of other nodes with offset to begin)
    //
    // tho I think that there should be another way Eular tours

    // saw in the previous question that the leaf skimming thing is somewhat slow

    // idea: pick any node as the root
    // use dfs
    //  - save the parent
    //  - to get the distance and the number of nodes in that subtree
    // use bfs
    //  - add the distance of the parent minus the distance of the subtree plus the number of nodes
    //      - get the distances of the parent to every node other than those in the subtree
    //      - also use the number of nodes to update the distances since we are one further

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> prev(n+1, -1);
    vector<long long> num(n+1, 1LL);
    vector<long long> dist(n+1, 0LL);

    // dfs
    auto dfs = [&](auto self, int cur, int pre) -> void {
        prev[cur] = pre;

        for (int nxt: g[cur]) {
            if (nxt == pre) {
                continue;
            }
            self(self, nxt, cur);

            // update the number of nodes and distance to nodes in the subtree
            num[cur] += num[nxt];
            dist[cur] += dist[nxt] + num[nxt];
        }
    };
    dfs(dfs, 1, 1);

    // bfs (skip the root since it has no parent)
    queue<pair<int, int>> q;
    for (int nxt: g[1]) {
        q.emplace(nxt, 1);
    }

    while (!q.empty()) {
        auto [cur, pre] = q.front(); q.pop();

        // 1. look at the parent's dist to every node
        // 2. remove the dist contribution of the subtree
        // 3. add the number of number of nodes not in the subtree to the dists
        // 4. add back i nthe dist contributions of the subtree
        // 5. update the number nodes whose distance we are considering
        dist[cur] += dist[pre] - (dist[cur] + num[cur]) + (num[pre] - num[cur]);
        num[cur] = num[pre];
        for (int nxt: g[cur]) {
            if (nxt == pre) {
                continue;
            }
            q.emplace(nxt, cur);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

