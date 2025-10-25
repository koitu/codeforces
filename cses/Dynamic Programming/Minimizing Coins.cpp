#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    // dp[i] = min number of coins to get to i
    vector<int> dp(x + 1, INT_MAX);
    sort(c.begin(), c.end(), greater<int>()); // doesn't actually matter

    dp[0] = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[j] < INT_MAX && j + c[i] <= x && dp[j] + 1 < dp[j + c[i]]) {
                dp[j + c[i]] = dp[j] + 1;
            }
        }
    }

    cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << endl;
}

