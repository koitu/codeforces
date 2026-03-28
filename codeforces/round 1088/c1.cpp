#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // sliding window: then just greedy fill the integer you are missing in the -1s
    // if b[i] = -1 and missing a[i] then b[i] = a[i] since each integer can only appear once in both arrays

    // get the first part
    set<int> diff;
    for (int i = 0; i < k; i++) {
        diff.insert(a[i]);
    }
    for (int i = 0; i < k; i++) {
        if (b[i] == -1) {
            continue;
        }

        // for each non -1 must be in a
        if (!diff.count(b[i])) {
            cout << "NO" << endl;
            return;
        }
        diff.erase(b[i]);
    }
    for (int j = k-1, i = k-1; i >= 0; i--) {
        while (j >= 0 && !diff.count(a[j])) {
            j--;
        }
        if (j < 0) {
            break;
        }

        // for each -1 assign the closest value in a not done yet
        if (b[i] != -1) {
            continue;
        }
        b[i] = a[j];
        diff.erase(a[j]);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    // maintain
    for (int i = k; i < n; i++) {
        // remember that there is only a single copy of each number in each array
        if (a[i-k] != b[i-k]) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] == -1) {
            b[i] = a[i];
        }
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
