#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


void solve() {
    int r, c, n; // rows, cols, number of cell towers
    cin >> r >> c >> n;

    vector<vector<int>> towr1(r, vector<int>(c, INT_MAX));
    vector<vector<int>> dist1(r, vector<int>(c, INT_MAX));
    vector<vector<int>> towr2(r, vector<int>(c, INT_MAX));
    vector<vector<int>> dist2(r, vector<int>(c, INT_MAX));

    vector<pii> locs;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        locs.emplace_back(x-1, y-1);
    }


    for (int i = n - 1; i >= 0; i--) {
        queue<pii> a;
        queue<pii> b;
        vector<vector<int>> visited(r, vector<int>(c, false));

        int depth = 0;

        // bfs
        a.push(locs[i]);
        while (!a.empty()) {
            while (!a.empty()) {
                auto [x, y] = a.front(); a.pop();

                if (x >= 0 && y >= 0 && x < r && y < c && !visited[x][y]) {
                    visited[x][y] = true;
                    if (depth <= dist1[x][y]) {
                        towr2[x][y] = towr1[x][y];
                        dist2[x][y] = dist1[x][y];

                        towr1[x][y] = i;
                        dist1[x][y] = depth;
                        b.push(make_pair(x+1, y));
                        b.push(make_pair(x-1, y));
                        b.push(make_pair(x, y+1));
                        b.push(make_pair(x, y-1));

                    } else if (depth <= dist2[x][y]) {
                        towr2[x][y] = i;
                        dist2[x][y] = depth;

                        b.push(make_pair(x+1, y));
                        b.push(make_pair(x-1, y));
                        b.push(make_pair(x, y+1));
                        b.push(make_pair(x, y-1));
                    }
                }
            }

            depth++;
            swap(a, b);
        }

    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << towr1[i][j] + 1 << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << towr2[i][j] + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
