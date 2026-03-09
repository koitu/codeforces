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


}

