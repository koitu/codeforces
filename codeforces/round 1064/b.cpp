#include <bits/stdc++.h>
using namespace std;


void solve() {
    // l = min(b, a/m)
    // l*m = min(b*m, a)
    long long a, b, n;
    cin >> a >> b >> n;

    //// be at the rightmost
    //int res = 0;
    //double cur = 0;
    //for (double i = n; i >= 1; i--) {
    //    if (abs(cur - min(b, a/i)) > 0.00001) {
    //        cur = min(b, a/i);
    //        res++;
    //    }
    //}

    // be at the leftmost

    // cout << res << endl;

    // idea: there will always be a x at the rightmost (tabs expand to fill)
    //  after that we can move to the leftmost (tabs are at their max size)
    
    // len of screen a
    // len of tab b
    // number of tab n

    if (b * n <= a || b == a) {
        // can we just keep the mouse at the right/leftmost?
        cout << 1 << endl;

    } else {
        cout << 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
