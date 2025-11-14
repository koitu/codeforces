#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int start, end;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        times[i] = make_pair(end, start);
    }
    sort(times.begin(), times.end());

//    // assume the array we are iterating over is sorted by increasing end times
//    // dp[i] = maximum movies we can take
//    // using i's start time we go back until the last movie we took has a end time outside and take dp of that +1
//    //
//    // we can also store pairs containing the max number we can take if we end with i tho the range of times are extreme
//    //
//    // if we binary search each time the total time is O(n log n) which is good enough
//    vector<int> dp(n, 0);
//    for (int k = 0; k < n; k++) {
//        // find the rightmost position j with times[j].first < s
//        // we want to find the largest one tho, are we sure that the rightmost position will always contain the largest dp[j]
//        const int s = times[k].second;
//
//        int i = 0;
//        int j = k-1;
//        int best = -1;
//        while (i <= j) {
//            int m = (i + j) / 2;
//            if (times[m].first < s) {
//                best = m;
//                i = m + 1;
//            } else {
//                j = m - 1;
//            }
//        }
//
//        if (best < 0) {
//            dp[k] = 1;
//        } else {
//            dp[k] = dp[best] + 1;
//        }
//    }

    // another idea: greedy
    // sort by ending time then take the next one as soon as we can
    // we are always making the optimal choice because it is never worst to pick a lesser ending time
    int res = 0;
    end = 0;
    for (int i = 0; i < n; i++) {
        if (end <= times[i].second) {
            res++;
            end = times[i].first;
        }
    }

    cout << res << endl;
}

