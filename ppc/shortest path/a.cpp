#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    long long a, b, c;
    vector<map<int, long long>> graph(n+1);
    // vector<vector<pair<int, int>>> graph(n+1);
    long long MAX = (long long)(1e9) * (long long)(INT_MAX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == b) {
            continue;
        }

        if (!graph[a].count(b)) {
            graph[a][b] = MAX;
            graph[b][a] = MAX;
        }
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
        // graph[a].emplace_back(b, c);
        // graph[b].emplace_back(a, c);
    }

    vector<long long> dist(n+1, MAX);
    vector<int> prev(n+1, 1);
    // typedef tuple<int, int, int> iii;
    typedef pair<long long, int> iii;

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    // pq.emplace(0, 1, 1);
    pq.emplace(0, 1);
    prev[1] = 1;
    dist[1] = 0;

    while (!pq.empty()) {
        // auto [d, cur, pre] = pq.top(); pq.pop();
        auto [d, cur] = pq.top(); pq.pop();

        if (d > dist[cur]) {
            continue;
        }
        // dist[cur] = d;
        // prev[cur] = pre;

        if (cur == n) {
            break;
        }

        for (auto &[nxt, w]: graph[cur]) {
            if (d + w < dist[nxt]) {
                dist[nxt] = d + w;
                prev[nxt] = cur;
                // pq.emplace(d + w, nxt, cur);
                pq.emplace(d + w, nxt);
            }
        }
    }
    // for (int i: dist) {
    //     cout << i << endl;
    // }

    if (dist[n] == MAX) {
        cout << -1 << endl;
        return;
    }

    int cur = n;
    vector<int> res;
    while (cur != 1) {
        res.push_back(cur);
        cur = prev[cur];
    }
    res.push_back(cur);
    reverse(res.begin(), res.end());

    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
