#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9 + 7;
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    // for coin combinations I we looped over locations then coins, which allowed for every coin to be in any place
    // for this we want our last iteration to be with the largest coins

    // loop over coins
    // loop over locations

    vector<int> dp(x + 1, 0);
    dp[0] = 1; // x >= 1 so we can store 1 in dp[0]

    for (int i = 0; i < n; i++) {
        int coin = c[i];

        for (int j = coin; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    cout << dp[x] << endl;
}

