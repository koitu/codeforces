#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9 + 7;
    const int n = 1e6 + 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
//    dp[1] = 2;
//    dp[2] = 8;

    // idea: we consider m to be the distance until we can make a horizontal cut in the tower
    //  - first part: how many ways can we create towers of len m without any cuts
    //  - second part: how to we efficiently multiply these values with dp[rest]
    //
    // first:
    //  - we can pick solid block at the end
    //  - we can pick two lines at the end
    //      - how many ways can we cut one or both of the lines to avoid a horizontal cut
    //      - at each of the m-1 possible positions we can either have cut on left, right, or no cut
    //
    //  second:
    //  - keep a sum of the previous dp
    //  - keep a sum where at each step we multply by 3 (we need one more height to reach the same place) and add the current dp

    int sum1 = 1;
    int sum2 = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (sum1 + sum2) % MOD;

        sum1 = (sum1 + dp[i]) % MOD;
        // sum2 = sum2*3 + dp[i];
        sum2 = (dp[i] + ((sum2 + ((sum2 + sum2) % MOD)) % MOD)) % MOD;
    }


    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        cout << dp[x] << endl;
    }
}

