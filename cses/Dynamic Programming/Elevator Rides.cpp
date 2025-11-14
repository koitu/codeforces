#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n, k;
    // cin >> n >> k;

    // multiset<int> e;
    // int v;
    // for (int i = 0; i < n; i++) {
    //     cin >> v;
    //     e.insert(-v);
    // }


    // // idea (greedy): attempt to take the largest person until we fill the elevator
    // // counterexample?: (k = 12) 8 7 6 3 2
    // // - I can't find one...., can I think of a proof?
    // // 
    // // dp[i] = the amount of elevators filled by the first i people?
    // 
    // int cur = k;
    // int res = 1;
    // for (int i = 0; i < n; i++) {
    //     auto it = lower_bound(e.begin(), e.end(), -cur);
    //     // cout << *it << endl;

    //     // doesn't exist
    //     if (it == e.end()) {
    //         res++;
    //         cur = k;
    //         continue;
    //     }

    //     cur += *it;
    //     e.erase(it);
    // }

    // cout << res << endl;
    

    // bitset dp
    //
    // since we look at subsets before moving to the next number
    // we can consider that each dp stores the number of elevators and number of weight on current elevator
    //
    // then we think about adding another
    // this should consider all the orders we can make
    //
    // brute force idea: consider all the orders we take the elevators in
    //  - pack them by order and use a new elevator when the prev gets full
    //  - 20! = too much
    //
    // bitset dp: by iteratoring over the bitset we also iterate over all the orders
    //  - dp[i] = minimum (# of rides, used cap) for state i
    //  - dp[0] = (0, 0)
    //  - dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] with w[j] added)
    //      - main idea: for each subset consider what to put at the end
    //      - by order of the bitset dp 
    //  - 2^20 * 20 = good enough
    //
    // proof: show that by iterating over bitset i we consider all the possible permuations of the weights
    // consider that at position l
    // - while (i & (1 << l)) == 0 we are checking all the ways that l can be last
    // - while (i & (1 << l)) == 1 we know all the ways that l can fit into a sequence using weights at and before l
    // - as i goes beyond l with k we will always update l and left before filling in l to k

    int n, k;
    cin >> n >> k;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<pair<int, int>> dp(1 << n, make_pair(INT_MAX, INT_MAX));
    dp[0] = make_pair(0, 0);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            // make the next pair by considering putting j at the end of subset i
            // while i is iterating to become bigger than (1 << (j + 1)) we will update this
            
            if (i & (1 << j)) continue;
            
            pair<int, int> nxt = dp[i];
            nxt.second += w[j];
            if (nxt.second == k) {
                nxt.first++;
                nxt.second = 0;
            } else if (nxt.second > k) {
                nxt.first++;
                nxt.second = w[j];
            }

            dp[i | (1 << j)] = min(dp[i | (1 << j)], nxt);
        }
    }

    // final thoughts
    // - imagine you are at position l
    // - you now consider all the ways to use the previous weights and l to make append before the next weight
    // -

    cout << dp[(1 << n) - 1].first + (dp[(1 << n) - 1].second > 0 ? 1 : 0) << endl;
}

