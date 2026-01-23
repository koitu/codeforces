#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    vector<pair<int, int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    
    int res = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                res++;
                q.emplace(i, j);
                // bfs set all to '#'

                while (!q.empty()) {
                    auto [ii, jj] = q.front(); q.pop();

                    if (ii >= 0 && ii < n && jj >= 0 && jj < m && maze[ii][jj] == '.') {
                        maze[ii][jj] = '#';

                        for (auto [di, dj]: dirs) {
                            q.emplace(ii + di, jj + dj);
                        }
                    }
                }
            }
        }
    }

    cout << res << endl;
}

