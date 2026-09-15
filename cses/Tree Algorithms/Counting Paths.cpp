#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<pair<int, int>> dn;
    int n;

    segtree(const vector<int>& depths, const vector<int>& nodes) {
        n = depths.size();
        dn = vector<pair<int, int>>(n * 2 + 5, make_pair(INT_MAX, INT_MAX));

        for (int i = 0; i < n; i++) {
            dn[i + n] = make_pair(depths[i], nodes[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            dn[i] = min(dn[i * 2], dn[i * 2 + 1]);
        }
    }

    int find(int l, int r) {
        // [l, r)
        l += n;
        r += n;

        pair<int, int> res = make_pair(INT_MAX, INT_MAX);
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, dn[l++]);
            if (r & 1) res = min(res, dn[--r]);
        }

        return res.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // idea: place the start and ends of the path at each node then perform dfs (note: start must be visited before end)
    // at each node track the sum comming in and the sum when finishing visiting the node
    // the count for eacah node is the absolute difference between in and out
    //
    // reasoning: consider the eular flattening of the tree
    //  - when performing dfs if we have a path from a to b we need to finish visiting a then we are done when we first visit b
    //  - along the dfs traversal from when we last visited a and when we first visit b consider the LCA
    //     - to the left of the LCA we are always exiting the nodes
    //     - to the right of the LCA we are always visiting the nodes for the first time
    //     - if there is a subtree not in the path we visit AND exit the every node
    //  - the "in" count is for visiting for the first time and the "out" count is done visiting
    //  - the "sum" is global and keeps track of how many paths we are in or underneith
    //  - issue: what if one path ends here and another begins here? won't the +1 and -1 cancel out since you come in as 1 and leave as 1
    //    - maybe for path enpoints we need to add them to the reuslt? think carefully about when to apply the starts and ends to the sum while in dfs
    //    - when to update same for path start and when to update sum for path end (i.e. before or after recording in and out)
    //
    //
    //    1
    //  2   3
    //     4 5
    //
    // paths: 1->3, 2->5, 1->4
    // res: 3, 1, 3, 1, 1
    //
    // rules: traverse the tree then
    //  - record the sum when visiting a node for the first time as "in"
    //  - update the sum based on paths
    //  - record the sum when visiting the node for the last time as "out"
    // 
    // in: 0, 2, 3, 3, 2
    // out: 0, 3, 0, 2, 1
    //
    // rules: traverse the tree then
    //  - record the sum every time you visit a node as "in"
    //  - update the sum based on paths
    //  - record the sum every time you exit a node as "out"
    //
    // in: 0+3, 2, 3+1, 2, 1
    // out: 2+3, 3, 2+1, 1, 0
    //
    //
    // flatten
    // 1, 2, 2, 3, 4, 4, 5, 5, 3, 1 (we can't find LCA from this...)
    // 1, 2, 1, 3, 4, 3, 5, 3, 1
    //
    // 2 -> 5 (LCA: 1)
    // 0, 0, 0, 0, 0, 0, 0, 0, 0
    // 1, 1, 1, 1, 1, 1, 1, 1, 1
    //

//    int a, b;
//    vector<vector<int>> g(n+1);
//    for (int i = 1; i < n; i++) {
//        cin >> a >> b;
//
//        g[a].push_back(b);
//        g[b].push_back(a);
//    }
//
//    vector<pair<int, int>> paths;
//    vector<int> extra(n+1, 0);
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b;
//
//        // deal with the case where the start and end nodes of a path are the same
//        if (a == b) {
//            extra[a]++;
//            continue;
//        }
//
//        // we don't know which is the start or the end so we will decide later
//        paths.emplace_back(a, b);
//    }


    // thinking:
    //  - while performing an Eular traversal keep a running sum
    //   - when we visit a node add start and sub end 
    //  - also need to track heights so that we can segment tree to find LCA later
    

    // looked at solution:
    // - for a path a->b
    // - add one to both count[a] and count[b]
    // - find c = LCA(a, b)
    // - subtrace one from count[c] and count[parent[c]]
    //  - node that if c is the root then don't modify count of parent (it doesn't have a parent)
    //
    // - then perform dfs to find the count sum of every node in every node's subtree
    //
    // - notice that if the node is on the path a->c we will add 1
    // - if a node is at c then we still add 1 + 1 - 1 = 1
    // - then if node has c in a subtree then the two additions will cancel out with the two subtractions
    //
    // - this problem doesn't even need seg tree (tho it could use it for LCA)


    // LCA: we can find how many levels up the LCA is however how to find the actual node?
    // - need to modify the segtree

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // traverse with dfs
    vector<int> nodes;
    vector<int> depths;
    vector<int> first(n+1);
    vector<int> parent(n+1);
    auto dfs1 = [&](auto self, int c, int p, int d) -> void {
        nodes.push_back(c);
        depths.push_back(d);
        first[c] = nodes.size() - 1;
        parent[c] = p;

        for (int s: g[c]) {
            if (s == p) {
                continue;
            }

            self(self, s, c, d+1);
            nodes.push_back(c);
            depths.push_back(d);
        }

        nodes.push_back(c);
        depths.push_back(d);
        parent[c] = p;
    };
    dfs1(dfs1, 1, 1, 0);

    // for (int i = 1; i <= n; i++) {
    //     cout << depths[first[i]] << " ";
    // }
    // cout << endl;

    // use the segtree to find LCA to fill out the tree with counts
    segtree st(depths, nodes);
    vector<int> count(n+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        count[a]++;
        count[b]++;
        int l = first[a];
        int r = first[b];
        if (r < l) {
            swap(l, r);
        }
        int lca = st.find(l, r + 1);
        count[lca]--;
        if (parent[lca] != lca) {
            count[parent[lca]]--;
        }
        // cout << a << " " << b << " " << lca << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << count[i] << " ";
    // }
    // cout << endl;

    auto dfs2 = [&](auto self, int c, int p) -> void {
        for (int s: g[c]) {
            if (s == p) {
                continue;
            }

            self(self, s, c);
            count[c] += count[s];
        }
    };
    dfs2(dfs2, 1, 1);

    for (int i = 1; i <= n; i++) {
        cout << count[i] << " ";
    }
    cout << endl;
}

