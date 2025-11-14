#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // dp[i][j] =
    //  - i -> subset of nodes
    //  - j -> current node
    //  - stores # of ways we can get to j with the nodes i
    //
    //  rec: for k adj to j sum dp[i | (1 << k)][k]
    //  base: dp[(1 << i)][i] = 1
    //
    // think about i grows, how it will have visited all the previous ones

    unordered_map<int, vector<int>> g;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    // // from itself we have one way to visit itself
    // for (int i = 0; i < n; i++) {
    //     dp[1 << i][i] = 1;
    // }
    dp[1 << 0][0] = 1;

    const int MOD = 1e9 + 7;

    for (int i = 0; i < (1 << n); i++) {
        // iterate over the subset of places we are visiting
        //
        // we look at all the node subsets before trying to add the next node
        
        for (int j = 0; j < n; j++) {
            // iterate over all the nodes
            
            // check:
            // - if j is in i
            // - number of paths with i nodes that end in j
            // if ((i & (1 << j)) == 0) continue;
            if (dp[i][j] == 0) continue;
            
            for (int k: g[j]) {
                // iterate over the neighbors of j
                
                // we are currently considering the edge j -> k

                // current state:
                // - from previously visited i
                // - we are currently at pos j
                // - we want to get to pos k
                
                // check:
                // - if j is in i
                // - number of paths with i nodes that end in j
                // - if k is already in i
                // if (dp[i][j] == 0 || (i & (1 << k))) continue;
                if (i & (1 << k)) continue;

                // add the number of ways to get to k
                dp[i | (1 << k)][k] = 
                    (dp[i | (1 << k)][k] + dp[i][j]) % MOD;
            }
        }
    }

    // return the number of ways to get from all nodes to the last node
    cout << dp[(1 << n) - 1][n - 1] << endl;
}

