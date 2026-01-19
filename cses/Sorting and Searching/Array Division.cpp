#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // binary search for the min sum to divide each subarray into
    long long l = 0; // begin at largest value
    long long r = 0; // begin at total sum
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    long long best = r;
    while (l <= r) {
        long long m = (l + r) / 2LL;
        
        int kk = 1; // start at one for the last one
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i];

            if (cur > m) {
                kk++;
                cur = a[i];
            }
        }

        if (kk <= k) {
            best = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << best << endl;
}

