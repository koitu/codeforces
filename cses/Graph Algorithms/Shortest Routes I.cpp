#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<long long, map<long long, long long>> g;
    long long a, b, c;
    for (long long i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (!g[a].count(b)) {
            g[a][b] = LLONG_MAX;
        }
        g[a][b] = min(c, g[a][b]);
    }

    // dijkstra
    vector<long long> dist(n+1, LLONG_MAX);
    // vector<long long> prev(n+1);

    // typedef tuple<long long, long long, long long> iii;
    // priority_queue<iii, vector<iii>, greater<iii>> pq;
    // pq.emplace(1, 1, 0);

    typedef pair<long long, long long> ii;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [dst, cur] = pq.top(); pq.pop();
        // cout << dst << " " << cur << endl;
        if (dst >= dist[cur]) {
            continue;
        }

        dist[cur] = dst;
        for (const auto [nxt, w]: g[cur]) {
            if (dist[cur] + w < dist[nxt]) {
                pq.emplace(dist[cur] + w, nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

