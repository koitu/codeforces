#include <bits/stdc++.h>
using namespace std;


int main() {
    const long long INF = (long long)(1e9) * 5000LL;

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // bellman-ford
    map<int, map<int, long long>> graph;
    map<int, set<int>> forward;
    map<int, set<int>> backward;
    long long a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        
        if (!graph[a].count(b)) {
            graph[a][b] = -INF;
        }
        graph[a][b] = max(c, graph[a][b]);

        forward[a].insert(b);
        backward[b].insert(a);
    }

    // we first need to isolate only for edges to feed into the final node (dfs)
    // vector<tuple<int, int, long long>> edges;
    // vector<bool> visited(n+1, false);
    // stack<int> q;
    // q.push(n);
    // while (!q.empty()) {
    //     int cur = q.top(); q.pop();

    //     if (visited[cur]) {
    //         continue;
    //     }
    //     visited[cur] = true;

    //     for (auto [prv, w]: graph[cur]) {
    //         edges.emplace_back(prv, cur, w);
    //         q.push(prv);
    //     }
    // }

    // we need to find all the edges that can be used in a direct connection to the dest
    // idea:
    // - find the nodes we can reach from 1
    // - find the nodes we can reach from n
    // - the overlap are the nodes we can use
    stack<int> q;

    q.push(1);
    vector<bool> visit_1(n+1, false);
    while (!q.empty()) {
        int cur = q.top(); q.pop();

        if (visit_1[cur]) {
            continue;
        }
        visit_1[cur] = true;

        for (int nxt: forward[cur]) {
            q.push(nxt);
        }
    }

    q.push(n);
    vector<bool> visit_n(n+1, false);
    while (!q.empty()) {
        int cur = q.top(); q.pop();
        if (visit_n[cur]) {
            continue;
        }
        visit_n[cur] = true;

        for (int prv: backward[cur]) {
            q.push(prv);
        }
    }

    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++) {
        visited[i] = visit_1[i] && visit_n[i];
    }

    vector<tuple<int, int, long long>> edges;
    for (const auto& [u, d]: graph) {
        for (const auto& [v, w]: d) {
            if (visited[u] && visited[v]) {
                edges.emplace_back(u, v, w);
            }
        }
    }

    // we have n nodes so we need to make at most n-1 jumps
    vector<long long> dist(n+1, -INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (const auto& [u, v, w]: edges) {
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    long long res = dist[n];

    // check for cycle
    // if some part of the graph is still increasing after n-1 steps
    // AND that part of the graph feeds into the final node
    // THEN we will go to infinity after sufficient steps
    for (const auto& [u, v, w]: edges) {
        if (dist[v] < dist[u] + w) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << dist[n] << endl;
}

