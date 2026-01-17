#include <bits/stdc++.h>
using namespace std;

//struct Tree {
//    int n;
//    int split;
//    bool split_x;
//
//    Tree *left = nullptr;
//    Tree *right = nullptr;
//
//    Tree(pair<int, int> v, int split_x) : n(1), split(split_x ? v.first : v.second), split_x(split_x) {};
//
//    Tree(vector<pair<int, int>>& vals, bool spilt_x) : split_x(split_x) {
//        n = vals.size();
//        cout << n << " " << split_x << endl;
//        for (int i = 0; i < n; i++) {
//            cout << (split_x ? vals[i].first : vals[i].second) << " ";
//        }
//        cout << endl;
//        const int mid = n/2;
//        int i = 0;
//
//        vector<pair<int, int>> left_vals;
//        if (split_x) {
//            sort(vals.begin(), vals.end());
//            split = vals[mid].first;
//
//            for (; i < n; i++) {
//                if (vals[i].first >= split) {
//                    break;
//                }
//                left_vals.push_back(vals[i]);
//            }
//
//        } else {
//            auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
//                return make_pair(a.second, a.first) < make_pair(b.second, b.first);
//            };
//            sort(vals.begin(), vals.end(), cmp);
//            split = vals[mid].second;
//
//            for (; i < n; i++) {
//                if (vals[i].second >= split) {
//                    break;
//                }
//                left_vals.push_back(vals[i]);
//            }
//        }
//
//        if (left_vals.size() == 1) {
//            left = new Tree(left_vals[0], !split_x);
//        } else if (left_vals.size() > 0) {
//            left = new Tree(left_vals, !split_x);
//        }
//
//        vector<pair<int, int>> right_vals;
//        for (; i < n; i++) {
//            right_vals.push_back(vals[i]);
//        }
//
//        if (right_vals.size() == 1) {
//            right = new Tree(right_vals[0], !split_x);
//        } else if (right_vals.size() > 0) {
//            right = new Tree(right_vals, !split_x);
//        }
//    };
//};
//
//int count_in(Tree *t, int x, int y) {
//    //  - for (x, y) to contain (a, b) we need x <= a and b <= y which is when x, y is to the left and above a, b
//    if (!t) {
//        return 0;
//    }
//
//    // for each split we can either be on the left or right side of it
//    if (t->split_x) {
//        // we want x <= a
//        if (x <= t->split) {
//            return count_in(t->left, x, y) + (t->right ? t->right->n : 0);
//        } else {
//            return count_in(t->right, x, y);
//        }
//
//    } else {
//        // we want b <= y
//        if (y > t->split) {
//            return count_in(t->left, x, y) + (t->right ? t->right->n : 0);
//        } else {
//            return count_in(t->right, x, y);
//        }
//    }
//}
//
//int count_out(Tree *t, int x, int y) {
//    //  - for (x, y) to be contained by (a, b) we need x >= a and b >= y which is when x, y is to the right and below a, b
//}

struct segtree {
    vector<int> a;
    int n;

    segtree(int n) : n(n) {
        a = vector<int>(2*2e5, 0);
    }

    int query(int l, int r) {
        // sum from indices [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += a[l++];
            if (r&1) res += a[--r];
        }

        // for (int i = 0; i < n*2; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        return res;
    }

    void add(int v, int m) {
        v += n;
        a[v] += m;
        for (; v > 1; v >>= 1) {
            a[v>>1] = a[v] + a[v^1];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // ideas:
    // - to find the number of ranges within a range -> go to the left idx and get number of values less than or equal to right (to the left of the idx)
    // - to find the number of ranges containing a range -> go to the left idx and get number of values greater than or equal to right (to the right of the idx)
    //
    // sqrt decomp: precompute this number for every sqrt then compute up to sqrt sqrt each time
    // - to precompute whould be to get the frequency for each right value to the right of the index of the left value
    //
    // ideas:
    // - what if there is a better way? as the current approach 
    // - think about putting ranges (x, y) onto a plot
    //  - for (x, y) to contain (a, b) we need x <= a and b <= y which is when x, y is to the left and above a, b
    //  - for (x, y) to be contained by (a, b) we need x >= a and b >= y which is when x, y is to the right and below a, b
    // - now the problem reduces to finding the number of pointers are in some area (remember to sub one for the init point)
    // - this can be done with a kd-tree/segment-tree like thing?

    // vector<pair<int, int>> vals;
    // vector<pair<int, int>> check;
    // int a, b;
    // for (int i = 0; i < n; i++) {
    //     cin >> a >> b;
    //     vals.emplace_back(a, b);
    //     check.emplace_back(a, b);
    // }

    // Tree *t = new Tree(vals, true);
    // cout << "yo" << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << count_in(t, check[i].first, check[i].second) << endl;
    // }
    

    // while kd-tree solution might work it's a bit too much hard
    // - instead we will use a segment tree! (lol)
    //
    // looked at a solution:
    // - main idea is that that by sorting from least to greatest (and reverse on second element) when we iterator from left to left on the ranges we know that one side is complete
    // - use a segment tree (or BIT) and coordiante compression on the second elements
    // - iterating over the ranges we want to find the number of elements larger/equal than the current right of the range that we already saw (number of ranges that contain the current range)
    // - do the same thing again but the other way with values smaller/equal than the current right (number of ranges contained by the current range)
    //
    // issue: need a segment tree or BIT...
    typedef tuple<int, int, int> iii;
    vector<iii> vals;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vals.emplace_back(a, b, i);
    }

    // note that there will not be duplicate ranges
    auto cmp = [](const iii& a, const iii& b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    };
    sort(vals.begin(), vals.end(), cmp);

    // for (int i = 0; i < n; i++) {
    //     cout << get<2>(vals[i]) << " ";
    // }
    // cout << endl;

    // coordinate compression
    set<int> c;
    for (int i = 0; i < n; i++) {
        c.insert(get<1>(vals[i]));
    }
    map<int, int> m;
    a = 0;
    for (auto d: c) {
        m[d] = a++;
    }
    vector<int> e;
    for (int i = 0; i < n; i++) {
        e.push_back(m[get<1>(vals[i])]);
        // cout << e.back() << " ";
    }
    // cout << endl << endl;

    // find the number of ranges contained by each range
    segtree s1(n);
    vector<int> res1(n);
    for (int i = n-1; i >= 0; i--) {
        res1[get<2>(vals[i])] = s1.query(0, e[i]+1);
        s1.add(e[i], 1);
    }

    // find the number of ranges that contain each range
    segtree s2(n);
    vector<int> res2(n);
    for (int i = 0; i < n; i++) {
        res2[get<2>(vals[i])] = s2.query(e[i], n+1);
        s2.add(e[i], 1);
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

