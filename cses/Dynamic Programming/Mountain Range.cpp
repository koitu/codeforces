#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // idea: range query for index of largest element?
    // every time we go to the largest element we have a choice to to left or right (and lose access to the other side)
    // - to deal with many largest elements we split on the largest element
    // - idea: quickselect?
    // - idea: instead of doing from top down, do from bottom up?
    //
    // create leafs from the lowest values
    // increment upwards, when we reach a value that is ajacent we have two cases
    // - if one side of it is greater than directly merge the smaller with current
    // - if smaller on both sides then take the longer one
    
    // doublely linked list?

//    vector<int> m(n);
//    map<int, vector<int>> v;
//    for (int i = 0; i < n; i++) {
//        cin >> m[i];
//        v[m[i]].push_back(i);
//    }

//    vector<int> dp(n, 0);
//    for (const auto &[k, idxs]: v) {
//        for (const int i: idxs) {
//            dp[i] = 1;
//
//            // I would like to be able to take the max of left and right
//            // but we must merge the chosen left/right node with the current one
//            // I can't think of any solution other than a doublely linked list (maybe try std::list?)
//            //
//            // e.g. 4 2 1 3
//        }
//    }

    int cur;
    list<pair<int, int>> dp; // store the best flight we can make
    map<int, vector<list<pair<int, int>>::iterator>> m; // map index to groups

    dp.push_back(make_pair(INT_MAX, INT_MAX)); // dummy first element allows dp.begin() to act as dp.end()
    for (int i = 0; i < n; i++) {
        cin >> cur;
        dp.push_back(make_pair(cur, 1)); // stores the current height and longest flight
        m[cur].push_back(prev(dp.end())); // get iterator to the current element
    }

    // merge adjacent when they are less or equal
    for (auto &[h, ps]: m) {
//        for (auto &[h, ps]: m) {
//            cout << h << ": ";
//            for (auto p: ps) {
//                cout << p->second << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for (auto [a1, a2]: dp) {
//            cout << a1 << " " << a2 << endl;
//        }
//        cout << endl;

        for (auto p: ps) {
            // 3 cases:
            // - greater than current -> do nothing
            // - equal to current -> take the max
            // - less to current -> take the max +1 (since we go down one step to it)

            // thinking about order of erase...
            // since iterators are pushed into the vector from left to right
            // if we erase from left to right we should be fine
            auto c = prev(p);
            if (c != dp.begin()) {
                // erase the one on the left
                if (h == c->first) {
                    p->second = max(p->second, c->second);

                    dp.erase(c);

                } else if (h > c->first) {
                    p->second = max(p->second, c->second + 1);

                    dp.erase(c);
                }
            }

            c = next(p);
            if (c != dp.end()) {
                // erase the current one and preserve the one on the right
                if (h == c->first) {
                    c->second = max(p->second, c->second);

                    dp.erase(p);

                } else if (h > c->first) {
                    // this is fine because we will never visit this lower element again
                    c->second = max(p->second, c->second + 1);
                    c->first = h;

                    dp.erase(p);
                }
            }
        }
    }

    cout << (--dp.end())->second << endl;
}

