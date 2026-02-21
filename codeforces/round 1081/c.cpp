#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, h, k;
    cin >> n >> h >> k;

    // n -> size of mag
    // h -> health of enemy
    // k -> time to reload

    // mag -> total damage of a magazine
    // note that for earlier magazines we can ignore the order (since they are all fired anyway)
    long long mag = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mag += a[i];
    }

    // number of values in the mag plus reload time times number of full mags
    // note: we want to leave just enough health for one round to finish the monster
    // long long res = (n + k) * ((h - 1) / mag);
    // h %= mag;
    // if (h == 0) {
    //     h += mag;
    // }
    int times = h / mag;
    if (h == mag * times) {
        times--;
    }
    long long res = (n + k) * times;
    h -= mag * times;

    // long long hh = h;
    // int cur = 0;
    // while (hh > 0) {
    //     hh -= a[cur++];
    // }
    // long long best = cur;
    // cur--;

    // // find the smallest value within cur and the largest value outside cur and swap them
    // long long sml = INT_MAX;
    // long long lrg = 0;

    // for (int i = 0; i < cur; i++) {
    //     sml = min(sml, a[i]);
    // }
    // for (int i = cur; i < n; i++) {
    //     lrg = max(lrg, a[i]);
    // }

    // however what if we have a really big round larger that we can swap to like the front?
    // binary search for earliest we can kill
    if (h <= 0) {
        cout << res << endl;
        return;
    }

    int i = 1;
    int j = n;
    int best = n;

    while (i <= j) {
        // m is the number of bullets we want to use
        int m = (i + j) / 2;

        long long sml = INT_MAX;
        long long lrg = 0;

        // get the smallest bullet we are using and largest bullet we are not and add the delta
        for (int i = 0; i < m; i++) {
            sml = min(sml, a[i]);
        }
        for (int i = m; i < n; i++) {
            lrg = max(lrg, a[i]);
        }

        long long hh = h - max(0LL, lrg - sml);
        for (int i = 0; i < m && hh > 0; i++) {
            hh -= a[i];
        }

        if (hh <= 0) {
            best = m;
            j = m - 1;
        } else {

            i = m + 1;
        }
    }

    cout << res + best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
