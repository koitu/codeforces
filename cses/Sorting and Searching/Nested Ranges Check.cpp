#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // given n ranges
    // determine for each range if it contains some other range and if some other range contains it
    // you many assume that no range appears more than once

    // output:
    // - for each range print if it contains some other range (1) or not (0)
    // - for each range print if it is contained by some other range (1) or not (0)
    // the next problem asks to count the values for each result

    // map of pair (range) to 3-tuple (index, if contains, if contained)
    // given a list of ranges and a single range how can we quickly check if there is a larger range?
    // make something like a kd-tree? flip between x and y axis and split on half the list
    //  - we would have to simplify the tree whenever we find a range within a range, otherwise incur heavy costs setting: contained by other range many times
    
    // what about just sorting the pairs and comparing the current one to the next ones
    // use the same trick as the russian nesting dolls (if first index is the same order the next one in reverse order)


    // auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    //     if (a.first == b.first) {
    //         return a.second > b.second;
    //     }
    //     return a.first < b.first;
    // };

    // map<pair<int, int>, tuple<int, bool, bool>> m;
    // set<pair<int, int>, cmp> s;
    // int a, b;
    // for (int i = 0; i < n; i++) {
    //     cin >> a >> b;
    //     m[make_pair(a, b)] = tuple<int, bool, bool>(i, false, false);
    //     s.emplace(a, b);
    // }

    // for (int i = 0, j = 1; j < n; j++) {

    // }
    
    // 1 <= n <= 2e5
    // 1 <= x < y <= 1e9


    // russian nesting doll solution:
    // sort by first value but when first value is equal then sort second value by reverse order
    // remove first values and find the longest increasing subsequence on ONLY THE SECOND VALUE
    //
    // for this problem at every possible left value store the max value we can go right?
    // e.g. [2, 3] and [1, 4]
    // the issue is how to prevent saying that the current list contains itself...
    // keep a count of the largest right sides  (if count > 1 then we can take the exact bound otherwise we can't)
    
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };

    vector<pair<int, int>> vals;
    vector<pair<int, int>> val;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vals.emplace_back(a, b);
        val.emplace_back(a, b);
    }
    sort(vals.begin(), vals.end(), cmp);

    vector<int> l;
    vector<int> r;
    for (auto [ll, rr]: vals) {
        l.push_back(ll);
        r.push_back(rr);
    }

    vector<pair<int, int>> max_r;
    vector<pair<int, int>> min_r;
    int best = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] > best) {
            best = r[i];
            count = 0;
        } 

        if (r[i] == best) {
            count++;
        }

        max_r.emplace_back(best, count);
    }

    best = INT_MAX;
    count = 0;
    for (int i = n-1; i >= 0; i--) {
        if (r[i] < best) {
            best = r[i];
            count = 0;
        }

        if (r[i] == best) {
            count++;
        }
        min_r.emplace_back(best, count);
    }
    reverse(min_r.begin(), min_r.end());

    // distance on a vector iterator should be O(1)
    // - for each range print if it contains some other range (1) or not (0)
    // - for each range print if it is contained by some other range (1) or not (0)
    vector<int> res1;
    vector<int> res2;
    for (int i = 0; i < n; i++) {
        auto [left, right] = val[i];
        auto it = lower_bound(l.begin(), l.end(), left);

        int idx = distance(l.begin(), it);
        auto [right_mx, count_mx] = max_r[idx];
        auto [right_mn, count_mn] = min_r[idx];

        if (right > right_mn) {
            res1.push_back(1);

        } else if (right == right_mn) {
            res1.push_back(count_mn > 1 ? 1 : 0);

        } else {
            res1.push_back(0);
        }

        if (right < right_mx) {
            res2.push_back(1);

        } else if (right == right_mx) {
            res2.push_back(count_mx > 1 ? 1 : 0);

        } else {
            res2.push_back(0);
        }
    }


    for (int i = 0; i < n; i++) {
        cout << res1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << res2[i] << " ";
    }
    cout << endl;
}

