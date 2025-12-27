#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // 2 x 7 1
    // min(|x - 2 + 7 - x + 1 - 7|)
    // =min(|- 2 + 1|)
    // no matter what x is chosen the result is is the same
    //
    // x 2 4 y
    // min(|2 - x + 4 - 2 + y - 4|)
    // min(|- x + y|)

    // all that matters is the last and first number
    // the rest of the choices are always zero (lexically min)

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        if (i != 0 && i != n-1 && res[i] == -1) {
            res[i] = 0;
        }
    }

    // minimize sum of difference array
    if (res[0] == -1 && res[n-1] == -1) {
        res[0] = 0;
        res[n-1] = 0;
    }
    if (res[0] == -1) {
        res[0] = res[n-1];
    }
    if (res[n-1] == -1) {
        res[n-1] = res[0];
    }

    cout << abs(res[0] - res[n-1]) << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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
