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

    map<char, pair<int, int>> dirs;
    dirs['U'] = make_pair(-1, 0);
    dirs['D'] = make_pair(1, 0);
    dirs['L'] = make_pair(0, -1);
    dirs['R'] = make_pair(0, 1);

    // bfs finds shortest path when all edges are 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'A') {

                maze[i][j] = '.';
                queue<tuple<int, int, char>> q;
                q.emplace(i, j, 'A');
                
                while (!q.empty()) {
                    auto [ii, jj, p] = q.front(); q.pop();

                    if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
                        continue;
                    }

                    if (maze[ii][jj] == 'B') {
                        // we are done
                        cout << "YES" << endl;
                        vector<char> res;

                        // iterate backwords saving the path we took to get here
                        int ci = ii;
                        int cj = jj;
                        maze[ci][cj] = p;
                        while (maze[ci][cj] != 'A') {
                            char c = maze[ci][cj];
                            auto [di, dj] = dirs[c];
                            res.push_back(c);

                            ci -= di;
                            cj -= dj;
                        }

                        cout << res.size() << endl;
                        cout << string(res.rbegin(), res.rend()) << endl;
                        return 0;
                    }

                    if (maze[ii][jj] != '.') {
                        continue;
                    }

                    // if is . then this is shortest path here
                    // otherwise there already exists a shortest path here
                    maze[ii][jj] = p;
                    for (auto [dp, d]: dirs) {
                        q.emplace(ii + d.first, jj + d.second, dp);
                    }
                }

                cout << "NO" << endl;
                return 0;
            }
        }
    }
}

