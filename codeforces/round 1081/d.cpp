#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // cost is sum of a[u] * d(1, u) over all nodes
    //
    // tree rooted at 1
    // for r = 1...n consider the subtree at node r (w.r.t. 1) and find where we can move it to maximize the cost
    // subtree at node r includes all nodes that must pass through r to reach 1 in their shortest path (only path)
    //
    // idea: compute tree without r
    // what occurs when we attach r to some node?
    // we get a[u] + d(1, u) extra score (for u in the subtree)

    // split the tree then find the max distance from root to put the subtree at?
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
