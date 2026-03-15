#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    double s = 1.0;
    vector<double> c(n);
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
        p[i] = 1.0 - (p[i] / 100);
    }

    // dp?
    // what is our state and how to search?
    // at each dp[i] we want both the largest points and the most stamina left
    // however if taking the current state yields greater than take it
    //
    // monotonic queue
    // decreasing by stamina left and increasing by points
    //
    //
    // note:
    //  - that stamina will always be non-increasing
    //  - always take the last one since there is no tasks after it
    //
    //  idea: start from back
    //  compare the effect of adding the current one vs no adding it
    //  greedy works?
    double best = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (c[i] + (p[i] * best) > best) {
            best = c[i] + (p[i] * best);
        }
    }

    cout << std::setprecision(12) << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
