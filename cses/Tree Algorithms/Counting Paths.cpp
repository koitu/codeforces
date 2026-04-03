#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<int> t;
    int n;

    segtree(const vector<int>& s) {
        n = s.size();
        t = vector<int>(n * 2 + 5);

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

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int, int>> paths;
    vector<int> extra(n+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        // deal with the case where the start and end nodes of a path are the same
        if (a == b) {
            extra[a]++;
            continue;
        }

        // we don't know which is the start or the end so we will decide later
        paths.emplace_back(a, b);
    }

    // thinking:
    //  - while performing an Eular traversal keep a running sum
    //   - when we visit a node add start and sub end
    //  - 


}

