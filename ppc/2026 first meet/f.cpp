#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> g(n-1);
    vector<int> r(n-1);
    vector<int> d(n-1);
    vector<int> c(n);
    for (int i = 0; i < n-1; i++) cin >> g[i];
    for (int i = 0; i < n-1; i++) cin >> r[i];
    for (int i = 0; i < n-1; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    // we want to find the great start time such that we can visit each position before c[i]
    // answer is guaranteed to exist

    // binary search...
    auto check = [&](long long time) -> bool {
        int v = n - k;
        if (time > c[0] && v-- <= 0) {
            return false;
        }

        for (int i = 0; i < n-1; i++) {
            long long period = g[i] + r[i];

            long long cur = time % period;
            if (cur >= g[i]) {
                time += period - cur;
            }
            time += d[i];

            // check that we reached the next point on time
            if (time > c[i+1] && v-- <= 0) {
                return false;
            }
        }
        return true;
    };

    long long ll = 0;
    long long rr = INT_MAX;
    long long best = ll;
    while (ll <= rr) {
        long long m = (ll + rr) / 2LL;
        if (check(m)) {
            best = m;
            ll = m + 1LL;
        } else {
            rr = m - 1LL;
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
