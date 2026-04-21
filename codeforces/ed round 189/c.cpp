#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // table of 2 x n cells
    // each cell red or black
    //
    // repaint cells so that we can partition cells in n pairs where
    // - cells in each pair have same color
    // - cells in each pair share a side (cells must be adjacent)
    //
    // find the min number of cells to repaint

    // sound like problem could be bitwise dp
    // use configuration of the previous to get the current, also need to encode which cells were taken or not

    // if they are taken then their color doesn't matter
    // only when not taken does their color matter

    // 4 bits -> 2 bits one for taken or not and other for color
    // lower two bits store color for easy iteration

    // notice we only need one bit to store taken both or not
    const int take = 0b100;
    const int red_up = 0b010;
    const int red_down = 0b001;

    vector<vector<int>> dp(n, vector<int>(8, 1e6));

    string up;
    string down;
    cin >> up;
    cin >> down;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = 0;

            // !! converts to bool
            if (!!(j & red_up) != (up[i] == 'R')) {
                dp[i][j]++;
            }
            if (!!(j & red_down) != (down[i] == 'R')) {
                dp[i][j]++;
            }
        }
    }

    dp[0][take] = dp[0][0];
    dp[0][take | red_up | red_down] = dp[0][red_up | red_down];
    int prev_prev = 0;

    for (int i = 1; i < n; i++) {
        // case 1: don't take
        // already done by previous for loop

        // case 2: take horizontally
        int prev = INT_MAX;
        for (int j = 0; j < 4; j++) {
            prev = min(prev, dp[i-1][take | j]);
        }
        dp[i][take] = prev + dp[i][0];
        dp[i][take | red_up | red_down] = prev + dp[i][red_up | red_down];

        // case 3: take vertically (need to do both)
        for (int j = 0; j < 4; j++) {
            dp[i][take | j] = min(dp[i][take | j], prev_prev + dp[i-1][j] + dp[i][j]);
        }

        // prev prev best result (since we filling in last two)
        prev_prev = prev;
    }

    // for (int j = 0; j < 8; j++) {
    //     for (int i = 0; i < n; i++) {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << endl;
    // }

    int res = INT_MAX;
    for (int j = 0; j < 4; j++) {
        res = min(res, dp[n-1][take | j]);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
