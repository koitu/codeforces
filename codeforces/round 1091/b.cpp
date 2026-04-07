#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // k is always 1
    int v;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v;
        a[i] = v;
    }

    int p;
    cin >> p;
    p--;

    // want to make all values in a equal to x
    // must perform even number of operations
    bool x = a[p];

    // starting from index p find the number of series of zeros to reach ends then get max and double
    int cl = 0;
    int cr = 0;

    bool cur = a[p];
    for (int i = p-1; i >= 0; i--) {
        if (cur == a[i]) {
            continue;
        }

        // when diff then add
        cur = a[i];
        if (cur != x) {
            cl++;
        }
    }

    cur = a[p];
    for (int i = p+1; i < n; i++) {
        if (cur == a[i]) {
            continue;
        }

        cur = a[i];
        if (cur != x) {
            cr++;
        }
    }

    // cout << cl << " " << cr << endl;
    cout << (max(cl, cr) * 2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
