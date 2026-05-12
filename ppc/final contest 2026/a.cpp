#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long Lll, Rll;
    cin >> Lll >> Rll;
    string L = to_string(Lll);
    string R = to_string(Rll);

    // notice that if there are difference at any but the last digit output is just zero
    // just multiply by everything and the L last digit
    if (L.size() != R.size()) {
        cout << 0 << endl;
        return;
    }

    // can check by dividing by 10 instead
    const int n = L.size();
    long long res = 1;
    for (int i = 0; i < n-1; i++) {
        if (L[i] != R[i]) {
            cout << 0 << endl;
            return;
        }
        res *= (long long)(L[i] - '0');
    }

    cout << res * (long long)(L[n-1] - '0') << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
