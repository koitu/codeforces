#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // book shop with n different books
    // know price and number of pages in each book
    //
    // have at most x dollars
    // want to maximize the number of pages
    // can buy each book at most once
    //
    // this is 0-1 knapsack
    //
    // dp[i][j] = most pages we can get from the first j books for at most i cost
    //          = max of "pick j" or "don't pick j"
    //          = max(dp[i - h[j]][j-1] + s[j], dp[i][j-1])
    //
    // remark: we cannot just sort and greedy (not optimal)

    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    vector<int> s(n);

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];

//    vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
//
//    for (int i = 1; i <= x; i++) {
//        // iterate over the max we can spend
//
//        for (int j = 1; j <= n; j++) {
//            // iterate over the books (indexed by 1)
//            
//            // only if the cost is within the bound
//            if (i - h[j-1] >= 0) {
//                // choose between not taking or taking
//                dp[i][j] = max(dp[i][j-1], dp[i - h[j-1]][j-1] + s[j-1]);
//
//            } else {
//                dp[i][j] = dp[i][j-1];
//            }
//        }
//    }
//
//    cout << dp[x][n] << endl;


    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j > 0; j--) {
            if (h[i] > j) {
                break;
            }

            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << endl;
}

