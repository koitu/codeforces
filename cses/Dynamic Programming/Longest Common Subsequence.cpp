#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // dp[i][j] = longest common subsequence from the first i values of a and first j values of b
    // if a[i] == b[j] then we can take dp[i-1][j-1] + 1 or use left/up
    // else dp[i][j] = diag/left/up
    
    vector<vector<int>> dp(n+1, vector(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i][j-1], dp[i-1][j]));
            } else {
                // choose to skip one of or both of the current character
                // dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j]));
                //
                // same? (since value of up/left will be at least that of the diagonal)
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = n;
    int j = m;
    vector<int> res;
    while (dp[i][j] > 0) {
        if (a[i-1] == b[j-1] && dp[i-1][j-1] == dp[i][j] - 1) {
            i--;
            j--;
            res.push_back(a[i]);

        } else if (dp[i][j-1] >= dp[i-1][j]) {
            // in case of tie it doesn't matter which direction we choose
            j--;

        } else {
            i--;

        }
    }
    reverse(res.begin(), res.end());

    cout << dp[n][m] << endl;
    for (int r: res) {
        cout << r << " ";
    }
    cout << endl;
}

