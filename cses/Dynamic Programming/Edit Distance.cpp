#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string sn, sm;
    cin >> sn >> sm;
    const int n = sn.length();
    const int m = sm.length();

    // dp[i][j] = is the min edit distance between the first i characters of sn and the first j characters of sm
    // - edit: dp[i-1][j-1] (free if last characters are the same)
    // - remove (from sn): dp[i-1][j]
    // - add (to sm): dp[i][j-1]

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        // remove i characters to match sn with empty string
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        // add i characters to match empty string with sm
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(
                    dp[i-1][j-1] + (sn[i-1] == sm[j-1] ? 0 : 1),
                    min(dp[i-1][j], dp[i][j-1]) + 1);
        }
    }

    cout << dp[n][m] << endl;
}

