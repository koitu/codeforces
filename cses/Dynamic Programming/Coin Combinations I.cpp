#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(c.begin(), c.end());

    vector<int> dp(x + 1, 0);
    // NOTE: x >= 1 so we can dp[0] as a storage
    dp[0] = 1;

    // dp[i] = number of ways we can make i
    // we will construct from previous dp[i] by assuming each of the possible coins as the last coin
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < c.size(); j++) {
            if (i - c[j] >= 0) {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;
}

