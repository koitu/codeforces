#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, k;
    cin >> t >> k;

    // holds the result where the last flower is a W
    const int MOD = 1e9 + 7;
    const int n = 1e5;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }
    for (int i = k; i <= n; i++) {
        // either choose R to be the last
        // or choose k Ws to be the last
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }

    int a, b;
    while (t--) {
        cin >> a >> b;
        cout << (dp[b] + (MOD - dp[a-1])) % MOD << endl;
    }
}
