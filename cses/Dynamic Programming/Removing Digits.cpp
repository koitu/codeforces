#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // store dp[i] = number of steps to get to i
    // starting from dp[n] iterate towards 1 subtracting every digit from n (max 6) and storing number of steps to get to the next steps
    
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n; i >= 1; i--) {
        if (dp[i] == INT_MAX) {
            continue;
        }

        int cur = i;
        while (cur > 0) {
            int digit = cur % 10;
            cur /= 10;

            if (i - digit >= 0) {
                dp[i-digit] = min(dp[i-digit], dp[i] + 1);
            }
        }
    }

    cout << dp[0] << endl;
}

