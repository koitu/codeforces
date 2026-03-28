#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677;

void solve() {
    int x, y;
    cin >> x >> y;

    // we have x 1s
    // we have y -1s
    
    // notice:
    // - when we only have one side then depends on even or not
    // - if we have x == y then min is something like all 1s on left and all -1s on right
    // - if one of x or y is greater than the other then we can always cancel out up to min(x, y) pairs of 1 and -1 so the problem reduces to max(x, y) - min(x, y)
    //
    // remember we want find an arragement that minimizes f(a)
    //
    // given z copies of one value how many ways can we split it such that all the bins have the same size

    long long z = max(x, y) - min(x, y);
    long long res = 1;

    for (long long m = 2; m <= z; m++) {
        if (z % m == 0) {
            res++;
        }
    }

    cout << (res % MOD) << endl;
    for (int i = 0; i < x; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < y; i++) {
        cout << -1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
