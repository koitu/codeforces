#include <bits/stdc++.h>
using namespace std;


int main() {
    const long long INF = (long long)(1e9) * 500LL * 500LL;
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Floyd-Warshall
    long long n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
    for (long long i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    map<long long, map<long long, long long>> graph;

    long long a, b, c;
    for (long long i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (!graph[a].count(b)) {
            graph[a][b] = INF;
        }
        if (!graph[b].count(a)) {
            graph[b][a] = INF;
        }
        graph[a][b] = min(c, graph[a][b]);
        graph[b][a] = min(c, graph[b][a]);
    }

    for (auto [u, d]: graph) {
        for (auto [v, w]: d) {
            if (u == v) {
                continue;
            }
            dist[u][v] = w;
        }
    }

    for (long long i = 1; i <= n; i++) {
        // middle part

        for (long long j = 1; j <= n; j++) {
            // source part

            for (long long k = 1; k <= n; k++) {
                // dest part
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (long long i = 0; i < q; i++) {
        cin >> a >> b;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
    }
}

