#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> a(n + 1, vector<int>(26, 0));
    vector<vector<int>> b(n + 1, vector<int>(26, 0));

    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a[i+1][c - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        b[i+1][c - 'a']++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            a[i+1][j] += a[i][j];
            b[i+1][j] += b[i][j];
        }
    }

    int l, r;
    int ac, bc;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        int res = 0;
        for (int j = 0; j < 26; j++) {
            res += (long long)abs((a[r][j] - a[l-1][j]) - (b[r][j] - b[l-1][j]));
        }
        cout << res / 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
