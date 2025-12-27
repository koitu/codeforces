#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
    // turn 1 = friend
    // turn 0 = you
    dp[0][1] = b[0];
    if (n > 1) {
        dp[1][1] = b[0] + b[1];
    }
    for (int i = 0; i < n; i++) {
        for (int turn = 0; turn < 2; turn++) {
            for (int step = 1; step <= 2; step++) {
                if (dp[i][turn] == INT_MAX) {
                    continue;
                }
                if (i + step >= n) {
                    continue;
                }

                dp[i+step][turn ^ 1] = min(
                        dp[i+step][turn ^ 1],
                        dp[i][turn] + (b[i+1] + (step > 1 ? b[i+2] : 0)) * (turn ^ 1));
            }
        }
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
