#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // let dp[i] = number of ways to construct i
    vector<int> dp(max(n, 6) + 1, 0);
    for (int i = 1; i <= 6; i++) {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        // the last roll will be one of 1 to 6
        for (int j = max(i - 6, 1); j < i; j++) {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }

    cout << dp[n] << endl;
}

