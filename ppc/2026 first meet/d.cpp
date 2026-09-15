#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // k is the size of the cells we are reducing it by
    int m = n / k;

    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<char>> res(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int offseti = i * k;
            int offsetj = j * k;
            char check = g[offseti][offsetj];

            for (int a = 0; a < k; a++) {
                for (int b = 0; b < k; b++) {
                    if (g[offseti + a][offsetj + b] != check) {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
            res[i].push_back(check);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
