#include <bits/stdc++.h>
using namespace std;

bool is_wall(const char c) {
    return c == 'X' || c == '?' || (c >= '0' && c <= '4');
}

void solve() {
    int n;
    cin >> n;

    // light bulbs will shine like a rook
    // blocked cell will block
    // must shine on all open cells
    // no two light bulbs shine on each other
    // any blocked cell with number on it must have exactly that number of light bulbs ajacent to it

    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<int>> shine(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '?') {
                for (int k = j - 1; k >= 0; k--) {
                    shine[i][k]++;
                    if (is_wall(g[i][k])) {
                        break;
                    }
                }
                for (int k = j + 1; k < n; k++) {
                    shine[i][k]++;
                    if (is_wall(g[i][k])) {
                        break;
                    }
                }
                for (int k = i - 1; k >= 0; k--) {
                    shine[k][j]++;
                    if (is_wall(g[k][j])) {
                        break;
                    }
                }
                for (int k = i + 1; k < n; k++) {
                    shine[k][j]++;
                    if (is_wall(g[k][j])) {
                        break;
                    }
                }
            }
        }
    }

    bool valid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '.') {
                valid = (shine[i][j] > 0);
            } else if (g[i][j] >= '0' && g[i][j] <= '4') {
                int c = 0;
                if (i > 0 && g[i-1][j] == '?') {
                    c++;
                }
                if (i < n-1 && g[i+1][j] == '?') {
                    c++;
                }
                if (j > 0 && g[i][j-1] == '?') {
                    c++;
                }
                if (j < n-1 && g[i][j+1] == '?') {
                    c++;
                }
                valid = (c == (g[i][j] - '0'));

            } else if (g[i][j] == '?') {
                valid = (shine[i][j] == 0);
            }

            if (!valid) {
                break;
            }
        }

        if (!valid) {
            break;
        }
    }

    cout << (valid ? 1 : 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
