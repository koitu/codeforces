#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    // multi source bfs
    int si, sj;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'A') {
                si = i;
                sj = j;
            }
            if (maze[i][j] == 'M') {
                q.emplace(i, j, 0);
            }
        }
    }

    map<char, pair<int, int>> dirs{
        {'D', {1, 0}},
        {'U', {-1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}}
    };

    // find the min distance of each square to the monsters
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    while (!q.empty()) {
        auto [i, j, d] = q.front(); q.pop();
        if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '#' || d >= dist[i][j]) {
            continue;
        }

        dist[i][j] = d;
        for (auto [_, dd]: dirs) {
            auto [di, dj] = dd;
            q.emplace(i + di, j + dj, d + 1);
        }
    }
    // the person must be able to arrive to each square at least one faster than any monster
    // so if we can decrease the dist update then the person can reach there
    vector<vector<char>> res(n, vector<char>(m));
    queue<tuple<int, int, int, char>> qq;
    qq.emplace(si, sj, 0, 'A');
    while (!qq.empty()) {
        auto [i, j, d, dir] = qq.front(); qq.pop();
        if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '#' || d >= dist[i][j]) {
            continue;
        }
        dist[i][j] = d;
        res[i][j] = dir;

        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
            cout << "YES" << endl;

            vector<char> result;
            while (res[i][j] != 'A') {
                result.push_back(res[i][j]);
                auto [di, dj] = dirs[res[i][j]];
                i -= di;
                j -= dj;
            }
            reverse(result.begin(), result.end());
            cout << result.size() << endl;
            cout << string(result.begin(), result.end()) << endl;

            return 0;
        }

        for (auto [dir, dd]: dirs) {
            auto [di, dj] = dd;
            qq.emplace(i + di, j + dj, d + 1, dir);
        }
    }

    cout << "NO" << endl;
}

