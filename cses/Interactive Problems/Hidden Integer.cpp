#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // binary search
    long long a = 1;
    long long b = 1e9;
    long long res = 1e9;

    string s;
    while (a <= b) {
        long long m = (a + b) / 2;

        cout << "? " << m << endl;
        cin >> s;

        // find x
        if (s == "YES") {
            // m < x
            a = m + 1;

        } else {
            // x <= m
            res = m;
            b = m - 1;
        }
    }

    cout << "! " << res << endl;
}

