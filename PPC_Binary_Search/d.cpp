#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // n is odd and at most 2e5
    // k is the number of operations you can make
    //
    // for each operation you can increase a value by 1
    // make the median of the array the largest possible

    // hint: binary search
    // idea: sort the array a from least to greatest
    //  - get the value of current median
    //  - use binary search to determine the max we can push up

    sort(a.begin(), a.end());
    long long median_idx = n / 2;
    long long i = a[median_idx];
    long long j = a[median_idx] + k;

    long long best = i;
    while (i <= j) {
        long long m = (i + j) / 2; // target median value
        long long v = 0;

        for (int i = median_idx; i < n; i++) {
            v += max(0LL, m - a[i]);
        }

        if (v <= k) {
            best = m;
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
