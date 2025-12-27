#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;
    for (int i = 0; i < n-1; i++) {
        b.push_back(a[i+1] - a[i]);
    }

    // we have two options: erase a delta from the end or merge two deltas
    // we can now merge two values together
    // get the merge that has the largest negative delta
    int best = INT_MAX;
    int best_idx = -1;
    for (int i = 0; i < n-2; i++) {
        // new value - old values
        int delta = abs(b[i] + b[i+1]) - abs(b[i]) - abs(b[i+1]);
        if (delta < best) {
            best = delta;
            best_idx = i;
        }
    }

    // for (int i = 0; i < n-1; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    int start = 0;
    int end = n-1;

    if (-abs(b[0]) < best) {
        best = -abs(b[0]);
        best_idx = -1;
        start++;
    }
    if (-abs(b[end-1]) < best) {
        start = 0;
        best = -abs(b[end-1]);
        best_idx = -1;
        end--;
    }
    // cout << best_idx << " " << b[best_idx] << " " << b[best_idx+1] << endl;
    // cout << best_idx << " " << b[best_idx] << " " << start << endl;

    int res = 0;
    for (int i = start; i < end; i++) {
        if (i == best_idx) {
            res += abs(b[i] + b[i+1]);
            i++;
        } else {
            res += abs(b[i]);
        }
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
