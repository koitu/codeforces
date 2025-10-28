#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // count the number of ways to get from upper-left to lower-right only moving right or down
    // cannot move onto a star
    char c;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> c;
            if (c == '*') {
                grid[i][j] = true;
            }
        }
    }

    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (grid[i][0]) {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i]) {
            break;
        }
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j]) {
                continue;
            }

            if (!grid[i-1][j]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            if (!grid[i][j-1]) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}

