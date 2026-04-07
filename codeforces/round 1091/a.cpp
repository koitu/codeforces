#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    int a = 0;
    int b;

    for (int i = 0; i < n; i++) {
        cin >> b;
        a += b;
    }
    // cout << a << k << endl;
    

    // don't use ability if don't need to to
    // then use ability when about to lose

    // can win without ability
    // Shaunak takes then Yash can't
    if ((a % 2) == 1) {
        cout << "YES" << endl;
        return;
    }

    // otherwise a is odd
    // using the ability at any time will convert to all k but start with Yash this time
    if (((k * n) % 2) == 0) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;



    // a %= 2;
    // if (a == 0) {
    //     a += n * k;
    // } else {
    //     cout << "YES" << endl;
    //     return;
    // }

    // a %= 2;

    // cout << (a == 0 ? "NO" : "YES") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
