#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

//    // min heap
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//        pq.push(make_pair(a[i], i));
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        // get min diff by looking at dist from cur to a or ground to a
//        diff = min(abs(a - cur), a);
//        res = max(res, diff);
//
//        cur = a;
//    }


//    int res = 0;
//    vector<bool> visit(n, false);
//    while (!pq.empty()) {
//        auto [v, idx] = pq.top(); pq.pop();
//        if (visit[idx]) {
//            continue;
//        }
//        visit[idx] = true;
//
//        res = max(res, v);
//        int cur = v;
//        for (int i = idx + 1; i < n; i++) {
//            if (visit[i] || abs(cur - a[i]) > res) {
//                break;
//            }
//            cur = a[i];
//            visit[i] = true;
//        }
//        cur = v;
//        for (int i = idx - 1; i >= 0; i--) {
//            if (visit[i] || abs(cur - a[i]) > res) {
//                break;
//            }
//            cur = a[i];
//            visit[i] = true;
//        }
//    }


//    for (int i = 0; i < n; i++) {
//        int diff = a[i];
//        if (i - 1 >= 0) {
//            diff = min(diff, abs(a[i] - a[i-1]));
//        }
//        if (i + 1 < n) {
//            diff = min(diff, abs(a[i] - a[i+1]));
//        }
//        res = max(res, diff);
//    }

    int i = 1;
    int j = 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        j = max(j , a[i]);
    }

    int res = j;
    while (i <= j) {
        const int m = (i + j) / 2;

        vector<bool> visit(n, false);
        for (int k = 0; k < n; k++) {
            if (visit[k] || a[k] > m) {
                continue;
            }
            visit[k] = true;

            for (int c = k + 1; c < n; c++) {
                if (visit[c] || abs(a[c-1] - a[c]) > m) {
                    break;
                }
                visit[c] = true;
            }
            for (int c = k - 1; c >= 0; c--) {
                if (visit[c] || abs(a[c+1] - a[c]) > m) {
                    break;
                }
                visit[c] = true;
            }
        }

        bool valid = true;
        for (int k = 0; k < n; k++) {
            if (!visit[k]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            res = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
