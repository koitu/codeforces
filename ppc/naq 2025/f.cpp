#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];

    sort(e.begin(), e.end());

    // can we just use greedy?
//    // take the farthest value from the mean and recompute (store the sum so recompute is fast)
//    // treat the (u - x)^2 as abs(u - x)
//    // since x^2 < y^2 iff |x| < |y|
//    long long s = 0;
//    for (int i = 0; i < n; i++) {
//        s += e[i];
//    }
//
//    int i = 0;
//    int j = n - 1;
//    for (int d = n; d > k; d--) {
//        long double m = (long double)(s) / (long double)(d);
//
//        if (abs(m - e[i]) > abs(m - e[j])) {
//            s -= e[i];
//            i++;
//        } else {
//            s -= e[j];
//            j--;
//        }
//    }
//
//    long double m = (long double)(s) / (long double)(k);
//    vector<long double> result(k);
//    for (int d = i; d <= j; d++) {
//        result[d - i] = (m - (long double)e[i]) * (m - (long double)e[i]);
//    }
//
//    sort(result.begin(), result.end());
//    long double res = 0;
//    for (int i = 0; i < k; i++) {
//        res += result[i];
//    }
//
//    cout << setprecision(16) << res << endl;


    // idea: sliding window
    long long s = 0;
    for (int i = 0; i < k - 1; i++) {
        s += e[i];
    }

    double best = DBL_MAX;
    for (int i = k; i <= n; i++) {
        s += e[i - 1];

        // get the mean
        double m = (double)(s) / (double)(k);
        double res = 0;

        // get the squared deviations
        for (int j = i - k; j < i; j++) {
            res += (m - (double)e[j]) * (m - (double)e[j]);
        }

        // get the best
        best = min(best, res);

        s -= e[i - k];
    }

    cout << setprecision(16) << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
