#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    typedef pair<int, int> ii;
    typedef tuple<int, int, int> iii;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    queue<iii> q;
    q.push(iii(0, 0, 0));

    vector<ii> moves{
        {2, 1},
        {1, 2},
        {-2, 1},
        {-1, 2},
        {2, -1},
        {1, -2},
        {-2, -1},
        {-1, -2},
    };

    // Dijstra -> bfs (since edge lens are all one)
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();

        for (auto [dx, dy]: moves) {
            int xx = x + dx;
            int yy = y + dy;
            int dd = d + 1;

            if (xx >= 0 && xx < n && yy >= 0 && yy < n && dist[xx][yy] > dd) {
                dist[xx][yy] = dd;
                q.push(iii(xx, yy, dd));
            }
        }
    }

    for (auto d: dist) {
        for (auto a: d) {
            cout << a << " ";
        }
        cout << endl;
    }
}

