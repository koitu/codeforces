#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // find the intersection with the (positive) y-axis
    double result = 1e8;
    double x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        // y = mx + b
        // m = rise/run
        // b = y - mx
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 < 0.0 && x2 < 0.0) || (x1 > 0.0 && x2 > 0.0)) {
            continue;
        }
        double m = (y1 - y2) / (x1 - x2);
        double b = y1 - (m * x1);
        if (b > 0.0) {
            result = min(result, b);
        }
    }

    if (result > 100) {
        cout << -1.0 << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
