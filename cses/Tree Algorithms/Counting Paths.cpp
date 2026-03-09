#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

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
}

