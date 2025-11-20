#include <bits/stdc++.h>
using namespace std;

// vector<int> c;

void solve() {
    long long y, x;
    cin >> y >> x;
    // idea: take z = max(y, x) then jump to (z, z)
    //  - then depending on the odd/even and which one of y/z is smaller we decrease until we get to the actual (y, z) coordinate

    long long m = max(y, x) - 1;
    // int b = c[m];
    // 1 + 2 (n * (n+1))/2
    // long long b = 1LL + 2LL * ((m * (m + 1LL)) / 2LL);
    long long b = 1LL + (m * (m + 1LL));

    if (y == x) {
        cout << b << endl;

    } else if (y > x) {
        // case: m is odd and y > x -> increasing when we move along col
        // case: m is even and y > x -> decreasing as we move along col
        if (m & 1LL) {
            cout << b + (y - x) << endl;
        } else {
            cout << b - (y - x) << endl;
        }

    } else {
        // case: m is odd and y < x -> decreasing as we move along row
        // case: m is even and y < x -> increasing as we move along row
        if (m & 1LL) {
            cout << b - (x - y) << endl;
        } else {
            cout << b + (x - y) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int cur = 1;
    // int jmp = 2;
    // c.push_back(cur);
    // while (cur < 1e9) {
    //     cur += jmp;
    //     jmp += 2;
    //     c.push_back(cur);
    // }

    // we cannnot calculate to 1e9
    // how to get sum_{i = 0 to n} 1 + 2*i
    // think of like a triangle
    // 1 + 2 (n * (n+1))/2

    int t;
    cin >> t;
    while (t--) solve();
}

