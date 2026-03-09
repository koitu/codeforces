#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // modified dijstra storing all prevoius with same value
    // extract the edges used in this solution
    // then topo sort?
    
    map<int, map<int, long long>> g;
    map<int, map<int, int>> dup;
    long long a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        // ensure:
        // - no self loops
        // - multiple edges between vertices (that are not all minimum)
        if (a == b) {
            continue;
        }

        if (!dup[a].count(b)) {
            g[a][b] = INT_MAX;
            g[b][a] = INT_MAX;
            dup[a][b] = 0;
            dup[b][a] = 0;
        }

        if (g[a][b] < c) {
            continue;
        }
        
        if (g[a][b] > c) {
            g[a][b] = c;
            g[b][a] = c;
            dup[a][b] = 0;
            dup[b][a] = 0;
        }

        dup[a][b]++;
        dup[b][a]++;
    }

    // find the shortest path keeping track of all previous paths with same dist
    long long MAX = (long long)(INT_MAX) * (long long)(1e6);
    vector<set<int>> prev(n+1);
    vector<long long> dist(n+1, MAX);

    typedef tuple<long long, int, int> lii;
    priority_queue<lii, vector<lii>, greater<lii>> pq;

    // dist, prev, cur
    pq.emplace(0, 1, 1);

    while (!pq.empty()) {
        const auto [d, p, c] = pq.top(); pq.pop();

        // when d is greater than dist then ignore
        if (d > dist[c]) {
            continue;
        }

        // if d is less than dist then reset prev
        if (d < dist[c]) {
            dist[c] = d;
            prev[c].clear();
        }

        // if d <= dist then insert to prev
        prev[c].insert(p);

        // go to the next
        for (auto [s, w]: g[c]) {
            if (d + w <= dist[s]) {
                pq.emplace(d + w, c, s);
            }
        }
    }

    // minimum price of such a route
    long long res1 = dist[n];

    // find the number of minimum price routes (keeping the duplicate edges)
    const long long MOD = 1e9 + 7;
    long long res2 = 1;
    for (int i = 2; i <= n; i++) {
        long long cur = 0;
        for (int j: prev[i]) {
            cur += dup[j][i];
            // cout << i << " " << j << " " << dup[j][i] << endl;
        }
        res2 *= cur;
        res2 %= MOD;
    }

    // to find the minimum flights and maximum flights we need to make this into a tree with every leaf being a 1 node
    // then find the min and max high of leafs
    map<int, set<int>> t;
    for (int i = 1; i <= n; i++) {
        for (int j: prev[i]) {
            if (j != i) {
                t[i].insert(j);
            }
        }
    }
    long long res3 = INT_MAX;
    long long res4 = 0;
    // node, dist
    vector<bool> visited(n+1, false);
    queue<pair<int, long long>> q;
    q.emplace(n, 0);

    while (!q.empty()) {
        const auto [c, d] = q.front(); q.pop();
        if (c == 1) {
            res3 = min(res3, d);
            res4 = max(res4, d);
            continue;
        }

        if (visited[c]) {
            continue;
        }
        visited[c] = true;

        for (int s: t[c]) {
            q.emplace(s, d + 1);
        }
    }

    cout << res1 << " " << res2 << " " << res3 << " " << res4 << endl;
}

