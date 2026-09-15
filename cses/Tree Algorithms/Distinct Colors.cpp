#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // nodes are given colors
    // determine for the subtree rooted at each node the number of distinct colors
    //
    // backtracking with a dict???
    // - why does this problem seem kind of hard...
    // - main issue: merger of dict when coming up
    //
    // another idea: count nodes in each subtree then count number of repeated colors
    // - merger problem again...
    //
    // is the merger problem even real?
    // - we only return when we traverse the entire subtree
    // - then the cost to merge is about the size of that subtree
    // - so the cost to traverse then merge a subtree is about twice the cost of traversing which is fine?
    //  - copy cost might be bad
    // - consider the stick graph: n(n+1)/2 or about n^2 operations since the merger gets bigger every time
    //  - it kind of just depends on which side we merge
    //  - if we merge smaller in the largest one then we can actually get a decent bound
    //      - recall disjoint set without path compression
    //
    // another thought:
    // - if the current node is a duplicate color then it only effects all its parents
    //
    // idea:
    // - topo sort!
    // - after topo sort keep a global distinct colors mem
    // - doesn't work consider if distinct color is in different subtree then current node
    //
    // idea:
    // - what sort of information do we get if we "invert" the tree
    // - if root is color c then every subtree of color c will be "tainted"
    //
    // idea:
    // - what if we just merge the smaller sides into the larger one
    //  - recall disjoint set without path compression
    //
    // todo bruh

    int n;
    cin >> n;

    vector<int> color(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    map<int, set<int>> mem;
    vector<int> res(n + 1, 0);
    auto dfs = [&](auto self, int cur, int pre) -> void {
        mem[cur];

        for (int nxt: g[cur]) {
            if (nxt == pre) continue;

            self(self, nxt, cur);
            for (auto [k, v]: mem[nxt]) {
                mem[cur][k] += v;
            }
        }

        res[cur] = mem[cur].size();
    };
    dfs(dfs, 1, 1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

