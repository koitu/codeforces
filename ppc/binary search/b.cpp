#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // n ingredients
    // needs a is grams of ingredient
    // has b is grams of ingreident
    // k can be transformed into any ingredient
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // binary search over the number of cookies we can make
    long long i = 0;
    long long j = INT_MAX;
    long long best = 0;
    while (i <= j) {
        long long m = (i + j) / 2LL;

        long long k_left = k;
        for (int i = 0; i < n; i++) {
            k_left -= max(a[i] * m - b[i], 0LL);

            if (k_left < 0) {
                break;
            }
        }

        if (k_left >= 0) {
            best = m;
            i = m + 1LL;
        } else {
            j = m - 1LL;
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
