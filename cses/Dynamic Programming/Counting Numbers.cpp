#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp(18, vector<int>(10, 0));
// 
// 
// int get_result(const string s) {
//     int result = 0;
//     const int n = s.length();
// 
//     int cur = s[n-1] - '0';
//     for (int i = 0; i < cur; i++) {
//         result += dp[n-1][i];
//     }
// 
//     for (int i = n - 2; i >= 0; i--) {
//         int prv = cur;
//         cur = s[i] - '0';
// 
//         for (int j = 0; j <= cur; j++) {
//             if (prv != j) {
//                 result += dp[i][j];
//             }
//         }
//     }
// 
//     return result;
// }


typedef long long ll;

// looked at solution...

// dp[a][b][c][d]
// - a -> (cur) the current digit being processed
// - b -> (prev_digit) the previous digit
// - c -> (leading_zeros) if we are currently looking at leading zeros (0 if the previous zeros are part of the number)
// - d -> (tight) if the current number formed so far is tight
ll dp[20][11][2][2];

ll solve(const string& s, int cur, int prev_digit, bool leading_zero, bool tight) {
    // cout << s << " " << cur << " " << prev_digit << " " << leading_zero << " " << tight << endl;
    // base case: entire number done
    if (cur == s.size()) {
        return 1LL;
    }

    // cout << dp[cur][prev_digit][leading_zero][tight] << endl;
    // if there is already a solution then return it
    if (dp[cur][prev_digit][leading_zero][tight] != -1) {
        return dp[cur][prev_digit][leading_zero][tight];
    }

    // iterate over all possible digits for the current position
    ll res = 0LL;
    int limit = tight ? (s[cur] - '0') : 9;

    for (int digit = 0; digit <= limit; digit++) {
        // check valid
        if (!leading_zero && digit == prev_digit) {
            continue;
        }

        // update params based on digit
        bool new_leading_zero = (leading_zero && digit == 0) ? true : false;
        bool new_tight = (tight && digit == limit) ? true: false;

        // recursive call to solve funtion
        res += solve(s, cur+1, digit, new_leading_zero, new_tight);
    }
    // cout << res << endl;

    // save and return result
    dp[cur][prev_digit][leading_zero][tight] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    a = to_string(stoll(a) - 1);

    //for (int i = 0; i < 20; i++) {
    //    for (int j = 0; j < 11; j++) {
    //        for (int x = 0; x < 2; x++) {
    //            for (int y = 0; y < 2; y++) {
    //                dp[i][j][x][y] = -1LL;
    //            }
    //        }
    //    }
    //}
    memset(dp, -1, sizeof(dp));
    ll res_a = (stoll(a) == -1) ? 0 : solve(a, 0, 10, 1, 1);

    // for (int i = 0; i < 20; i++) {
    //     for (int j = 0; j < 11; j++) {
    //         for (int x = 0; x < 2; x++) {
    //             for (int y = 0; y < 2; y++) {
    //                 dp[i][j][x][y] = -1LL;
    //             }
    //         }
    //     }
    // }
    memset(dp, -1, sizeof(dp));
    ll res_b = solve(b, 0, 10, 1, 1);

    cout << res_b - res_a << endl;

//    // numbers with 1 digit have a count of one
//    for (int i = 0; i < 10; i++) {
//        dp[0][i] = 1;
//    }
//
//    for (int i = 1; i < 18; i++) {
//        for (int j = 0; j < 10; j++) {
//            for (int k = 0; k < 10; k++) {
//                if (j != k) {
//                    dp[i][j] += dp[i-1][k];
//                }
//            }
//        }
//    }
//
//    cout << get_result("9") << endl;
//    cout << get_result("89") << endl;
//    cout << get_result("99") << endl;
//    cout << get_result("001") << endl;
//    cout << get_result("899") << endl;
//    cout << get_result("999") << endl;
//    cout << get_result("0001") << endl;
//    cout << get_result(a) << " " << get_result(b) << endl;
//    cout << get_result(a) - get_result(b) << endl;



}

