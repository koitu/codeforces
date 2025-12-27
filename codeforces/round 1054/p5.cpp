#include <bits/stdc++.h>

using namespace std;
// using vi = vector<int>;

struct dm {
    unordered_map<int, int> m;
    int distinct = 0;

    void add(const int a) {
        if (m[a] == 0) {
            distinct++;
        }
        m[a]++;
    }

    void rem(const int a) {
        m[a]--;
        if (m[a] == 0) {
            distinct--;
        }
    }
};

// void solve() {
//     // this is (probably) correct but I'm not sure if it is fast enough
//     int n, k, l, r;
//     cin >> n >> k >> l >> r;
// 
//     dm d;
//     d.m.reserve(n);
//     vector<int> v(n, 0);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//         d.m[v[i]] = 0;
//     }
// 
//     // 1 <= k <= n <= 2*1e5
//     // 1 <= l <= r <= n
// 
//     l = max(k, l);
//     if (l > r) {
//         cout << 0 << endl;
//         return;
//     }
//     int diff = r - l;
// 
//     int res = 0;
//     int i = 0;
//     int j = 0;
//     for (; j < n; j++) {
//         d.add(v[j]);
// 
//         while (d.distinct == k) {
// 
//         }
// 
//     }
// 
//     // AHHHHHHHHH
//     // need to keep the core of the sequence and check the number of ways to get more than l and less than r
//     // subsequences that contain the core
// 
// 
// //     for (int i = 0; i < l; i++) {
// //         d.add(v[i]);
// //     }
// //     if (d.distinct == k) {
// //         res++;
// //         for (int j = 0; j < diff; j++) {
// //             if (d.con(v[l + j])) {
// //                 res++;
// //             } else {
// //                 break;
// //             }
// //         }
// //     }
// // 
// //     for (int i = l; i < n; i++) {
// //         d.add(v[i]);
// //         d.rem(v[i - l]);
// //         if (d.distinct == k) {
// //             res++;
// //             for (int j = 0; j < diff; j++) {
// //                 if (d.con(v[i + j + 1])) {
// //                     res++;
// //                 } else {
// //                     break;
// //                 }
// //             }
// //         }
// //     }
// 
//     cout << res << endl;
// }


void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // left of sliding window
    int i = 0;

    // right of sliding window with exactly k distinct
    dm x;
    int xi = 0;

    // right of sliding window with at most k distinct
    dm y;
    int yi = 0;

    // treat as 1 indexed
    long long res = 0;
    while (true) {
        // go to the edge
        while (xi < n) {
            if (x.distinct == k) {
                break;
            }

            x.add(v[xi]);
            xi++;
        }

        // push y over the edge then come back
        while (yi < n) {
            y.add(v[yi]);
            yi++;

            if (y.distinct > k) {
                yi--;
                y.rem(v[yi]);

                break;
            }
        }

        
        if (x.distinct < k || y.distinct < k) {
            break;
        }

        // cout << "- " << i+1 << " " << xi << " " << yi << endl;

        // get result
        // number of valid endpoints that lie in [x-1, ..., y-1]

        // k >= 1 so we are fine
        while (x.distinct == k && i < n) {
            res += (long long)max(0, min(yi, i + r) - max(xi, i + l) + 1);
            x.rem(v[i]);
            y.rem(v[i]);
            i++;
        }

        // TODO: too slow, need coordinate compression....
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
