#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int start;
    int end;
    int profit;
    typedef tuple<int, int, int> iii;
    vector<iii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> start >> end >> profit;
        a[i] = make_tuple(end, start, profit);
    }
    sort(a.begin(), a.end());

    // what is the max profit we can get if we take i
    // -> what is the max profit we can get with end times before some start time
    // -> do I need to make a linked list again?...
    //
    // idea: dp[i] = what is the max profit we can get from the first i
    // 
    // how can I make this better than O(N^2)
    // idea: use dp[i] and then binary search to find the rightmost end value that is less than times[i]
    // idea: store the max profit then binary search for the max previous profit we can get

    // end times are monotonically increasing
    // total profits should also be monotonically increasing
    vector<long long> dp(n, 0);
    dp[0] = get<2>(a[0]);
    for (int k = 1; k < n; k++) {
        const auto [e, s, p] = a[k];

        int i = 0;
        int j = k - 1;
        int best = -1;
        while (i <= j) {
            const int m = (i + j) / 2;
            const auto [me, ms, mp] = a[m];

            if (me < s) {
                best = m;
                i = m + 1;
            } else {
                j = m - 1;
            }
        }

        if (best == -1) {
            // either use the last one or don't
            // when best is -1 then could not fine any end value that is less the current s
            dp[k] = max((long long)p, dp[k-1]);
        } else {
            // either use the last one or don't
            // when best is not -1 we have found the largest end value the is less than the current s
            dp[k] = max(dp[best] + (long long)p, dp[k-1]);
        }
    }

    cout << dp[n-1] << endl;
}

