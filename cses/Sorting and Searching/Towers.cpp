#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // given n cubes in a certain order with weights
    // a cube cannot placed on top of another if it is heavier (same or ligher is fine)
    // 
    // for each cube we can either place on top of a tower or start a new one
    // what is the minimum number of towers at the end
    //
    // 2*1e5 cubes
    // 1e9 max weight
    
    // what is the minimum number of decreasing sequeneces we can make
    // we already saw how to this with the increasing sequeneces so we can reverse the numbers and just do the same thing


    // // this doesn't work
    // vector<pair<int, int>> vals;
    // int a;
    // for (int i = 0; i < n; i++) {
    //     cin >> a;
    //     vals.emplace_back(-a, i);
    // }
    // sort(vals.begin(), vals.end());

    // for (auto [k, v]: vals) {
    //     cout << k << " " << v << endl;
    // }
    // cout << endl;

    // int res = 0;
    // int cur = INT_MAX;
    // for (auto [_, idx]: vals) {
    //     if (idx < cur) {
    //         res++;
    //     }

    //     cur = idx;
    // }

    // cout << res << endl;
    // idea: consider that for each number there are two paths:
    // - the number is greater than any number before it -> must make a new tower
    // - the number is less than some number before it
    //  - we can either take it or not -> if take then replace the smallest number greater with it

    // can this be done with some greedy method?
    //
    // idea: what if we start from the back?
    // find the number of (not strictly) increasing sequences required to cover the entire things


    // insight: when the number is less than some number before it we can either make a new tower or take it
    // - however we can always just take it now!
    // - if we make a new tower and some number larger than current but smaller than prev comes it would be better to create a new tower with it than current
    set<int> a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;

        const auto it = a.lower_bound(b);
        if (it == a.end()) {
            a.insert(b);

        } else if (!a.count(b)) {
            a.erase(it);
            a.insert(b);
        }
    }

    cout << a.size() << endl;

    // 10
    // 6 4 7 2 10 4 9 5 4 10
    // res: 4
    //
    // 6 7 10 10
    // 4 4 9
    // 2 5
    // 4

    // 1 9 1 7 8 5 4 3 2 1
    //
    // 1 9
    // 1 7 8
    // 5
    // 4
    // 3 
    // 2
    // 1






}

