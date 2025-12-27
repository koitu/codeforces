#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> d{
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

void solve() {
    int r, c, s;
    cin >> r >> c >> s;

    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<int>> dist(r, vector<int>(c, 0));
    priority_queue<tuple<int, int, int>> q;
    for (int i = 0; i < r; i++) {
        q.push(make_tuple(s+1, i, -1));
        q.push(make_tuple(s+1, i, c));
    }
    for (int i = 0; i < c; i++) {
        q.push(make_tuple(s+1, -1, i));
        q.push(make_tuple(s+1, r, i));
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '#') {
                dist[i][j] = s+1;
                q.push(make_tuple(s+1, i , j));
            }
        }
    }

    while(!q.empty()) {
        auto [p, x, y] = q.top(); q.pop();
        for (auto [xd, yd]: d) {
            int i = x + xd;
            int j = y + yd;

            if (i >= 0 && i < r && j >= 0 && j < c && p - 1 > dist[i][j]) {
                dist[i][j] = p - 1;
                q.push(make_tuple(p - 1, i, j));
            }
        }
    }

//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << dist[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int best = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist[i][j] == 0 && !visited[i][j]) {
                int cur = 0;
                queue<pair<int, int>> a;
                queue<pair<int, int>> b;
                a.push(make_pair(i, j));

                while (!a.empty()) {
                    while (!a.empty()) {
                        auto [x, y] = a.front(); a.pop();
                        if (visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        cur++;

                        for (auto [xd, yd]: d) {
                            int ii = x + xd;
                            int jj = y + yd;

                            if (ii >= 0 && ii < r && jj >= 0 && jj < c && dist[ii][jj] == 0) {
                                b.push(make_pair(ii, jj));
                            }
                        }
                    }
                    swap(a, b);
                }

                best = max(best, cur);
            }
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
