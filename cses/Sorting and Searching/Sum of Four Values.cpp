#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    // n is up to 1000
    // even 1e9 is too much
    
    // idea: split the array into half, then we have 5 cases:
    // - all values are to the left -> recurse until like 10 elements?
    // - 3 left, 1 right -> ???
    // - 2 left, 2 right -> comparing two sets of 500*500 = 250,000 elements
    // - 1 left, 3 right
    // - all values are to the right
    // is this really fast enough?
    // T4(n) = 2*T4(n/2) + 2*T3(n/2)*n + T2(n/2)^2
    //
    // T3(n) = n^2 * log n
    // T2(n) = n * log n
    // 
    // just the T3(n) * n is already too much?
    //
    // can also sort and compare to prune branchs that are just not possible

    // vector<pair<int, int>> a;
    // int v;
    // for (int i = 0; i < n; i++) {
    //     cin >> v;
    //     a.emplace_back(v, i);
    // }
    // sort(a.begin(), a.end());

    // vector<long long> b;
    // for (int i = 0; i < n; i++) {
    //     b.push_back(a[i].first);
    // }

    // remember that lower_bound can be used to binary search a sorted array compared to find which will search linearly

    // idea: save a set of possible sums of two values
    // double for loop for the other elements
    // while removing already seen value pairs
    //
    // note that approx log(1000) = 7
    // runtime: 1000 * 1000 * 7 + 1000 * 1000 * 7


    //vector<long long> a(n);
    //for (int i = 0; i < n; i++) {
    //    cin >> a[i];
    //}

    //map<long long, set<int>> m;
    //for (int i = 0; i < n; i++) {
    //    for (int j = i + 1; j < n; j++) {
    //        m[a[i] + a[j]].insert(i * n + j);
    //    }
    //}

    //for (int i = 0; i < n; i++) {
    //    for (int j = i + 1; j < n; j++) {
    //        // issue: while this works for when i and j are the same
    //        // how do isolate for all i not cur_i and all j not cur_j

    //        long long cur = a[i] + a[j];
    //        m[cur].erase(i * n + j);
    //        if (m[cur].size() == 0) {
    //            m.erase(cur);
    //        }

    //        if (m.count(x - cur)) {
    //            int ij = *m[x - cur].begin();
    //            cout << (ij / n) + 1 << " " << (ij % n) + 1 << " " << i + 1 << " " << j + 1 << endl;
    //            return 0;
    //        }
    //    }
    //}

    //cout << "IMPOSSIBLE" << endl;
    


    // idea: (i'm not sure why I'm so brainded)
    // get all the possible 2-sums then 

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<long long, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m[a[i] + a[j]].emplace_back(i, j);
        }
    }

    for (const auto& [v, p1]: m) {
        if (m.count(x - v)) {
            const auto& p2 = m[x - v];

            for (const auto& [i1, j1]: p1) {
                for (const auto& [i2, j2]: p2) {
                    if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
                        cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
                        return 0;
                    }
                }
            }

            // prevent from going over it again by trying to delete the other one
            // m.erase(v);
            if (v != x - v) {
                m.erase(x - v);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

