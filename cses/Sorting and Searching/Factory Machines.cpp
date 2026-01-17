#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, t;
    cin >> n >> t;

    // binary search!
    vector<long long> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    // worst case: t == 1e9 and one machine that takes 1e9 time
    long long l = 1LL;
    long long h = 1e9 * 1e9; // max amount of time
    long long best = h;

    while (l <= h) {
        const long long m = (h + l) / 2;

        long long tt = 0;
        for (int i = 0; i < n; i++) {
            tt += m / vals[i];
            if (tt >= t) {
                break;
            }
        }

        if (tt >= t) {
            best = m;
            h = m - 1;

        } else {
            l = m + 1;
        }
    }

    cout << best << endl;
}

