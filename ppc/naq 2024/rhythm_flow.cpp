#include <bits/stdc++.h>
using namespace std;


int dist(int a, int b) {
    int i = abs(a - b);

    if (i <= 15) {
        return 7;
    } else if (i <= 23) {
        return 6;
    } else if (i <= 43) {
        return 4;
    } else if (i <= 102) {
        return 2;
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // [0, 15] -> 7
    // (15, 23] -> 6
    // (23, 43] -> 4
    // (43, 102] -> 2
    // outside -> 0
    
    // match each button press with at most one exp button press
    //
    // order must be maintained between the matching

    vector<int> exp(n+1,0);
    vector<int> act(m+1,0);
    for (int i = 0; i < n; i++) cin >> exp[i];
    for (int i = 0; i < m; i++) cin >> act[i];

    // each autual button press must be matched with at most one expected button press
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = dist(exp[0], act[0]);
    for (int i = 1; i < m; i++) dp[0][i] = max(dp[0][i-1], dist(exp[0], act[i]));
    for (int i = 1; i < n; i++) dp[i][0] = max(dp[i-1][0], dist(exp[i], act[0]));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(
                    dp[i-1][j-1] + dist(exp[i], act[j]), 
                    max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n-1][m-1] << endl;

    // dp[i][j] = best score so far using i from exp and j from act
    // (last ai we matched) (last bi we consdered)
    // take dp[i][j] over the max of dp[i-1][k] + something something something


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
