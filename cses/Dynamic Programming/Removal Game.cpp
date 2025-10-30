#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // line of n numbers
    // two players take turns taking the first or last element
    // what is the max value that the first player can get if both players are playing optimally

    int n;
    cin >> n;

    vector<long long> v(n);
    vector<long long> prefix(n+1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        prefix[i+1] = prefix[i] + v[i];
    }

    // dp[i][j] = max the player can get from i to j of the input
    // doesn't matter which player as we want to max
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = v[i];
    }

    // d is the distance between i and j (we want to start from 1 and go to n-1)
    for (int d = 1; d < n; d++) {
        for (int j = d; j < n; j++) {
            int i = j - d;

            // get the max of taking the left or taking the right
            // idea: min-max, since the game we are playing is zero-sum we can maximize us by minimizing the opponent
            //  - how do we calculate our score then?
            //  - we need to get our max from the next-next turn
            //  - or we can also keep a prefix sum and subtract what they get to get what we get

            // if (dp[i+1][j] <= dp[i][j-1]) {
            //     // take the left (sum from i to j)
            //     dp[i][j] = (prefix[j+1] - prefix[i]) - dp[i+1][j];

            // } else {
            //     // take the right (sum from i to j)
            //     dp[i][j] = (prefix[j+1] - prefix[i]) - dp[i][j-1];
            // }

            dp[i][j] = (prefix[j+1] - prefix[i]) - min(dp[i+1][j], dp[i][j-1]);
        }
    }

    cout << dp[0][n-1] << endl;
}

