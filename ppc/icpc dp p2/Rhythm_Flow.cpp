#include <bits/stdc++.h>
using namespace std;

long long score(long long a, long long b) {
    long long d = abs(a - b);
    if (d <= 15) {
        return 7;
    }
    if (d <= 23) {
        return 6;
    }
    if (d <= 43) {
        return 4;
    }
    if (d <= 102) {
        return 2;
    }
    return 0;
}

void solve() {
    long long n, m;
    cin >> n >> m;

    // n is number of exp button presses
    // m is number of actual button presses
    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // knapsack?
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + score(a[i-1], b[j-1]));
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
