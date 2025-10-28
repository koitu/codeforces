#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

//    // number of times we subtract the smaller edge from the larger one -1
//    // this greedy method doesn't work
//    int res = 0;
//    while (a > 0 && b > 0) {
//        if (a > b) {
//            swap(a, b);
//        }
//
//        // assume a <= b
//        cout << a << " " << b << endl;
//        b -= a;
//        res++;
//    }
//
//    cout << res - 1 << endl;


    // let dp[i][j] = least cuts to turn rect of i x j to squares
    // we will just try to fill up the upper triangle (symmetric)
    vector<vector<int>> dp(501, vector<int>(501, INT_MAX));
    for (int i = 0; i <= 500; i++) {
        dp[0][i] = 0;
        dp[i][i] = 0;
    }

    auto get_dp = [&](int v1, int v2) -> int {
        if (v1 > v2) {
            return dp[v2][v1];
        }
        return dp[v1][v2];
    };

    // something about 500^3 which is about 1e8
    for (int i = 1; i <= 500; i++) {
        for (int j = i + 1; j <= 500; j++) {
            // search across all the horizontal and vertical cuts we can make

            int hi = i / 2;
            for (int cut = 1; cut <= hi; cut++) {
                dp[i][j] = min(dp[i][j], get_dp(cut, j) + get_dp(i - cut, j) + 1);
            }

            int vi = j / 2;
            for (int cut = 1; cut <= vi; cut++) {
                dp[i][j] = min(dp[i][j], get_dp(i, cut) + get_dp(i, j - cut) + 1);
            }
        }
    }

    cout << get_dp(a, b) << endl;
}

