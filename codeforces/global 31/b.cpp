#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    string res = "";
    string cur = "";

    for (int i = 0; i < n; i++) {
        cin >> cur;
        string res1 = res + cur;
        string res2 = cur + res;

        if (res1 < res2) {
            res = res1;
        } else {
            res = res2;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
