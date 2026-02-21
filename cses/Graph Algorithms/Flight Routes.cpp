#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    map<int, map<int, vector<long long>>> graph;

    // idea: use dikjstra with top 10 dist at to every node (use multiset?)
    int a, b;
    long long c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        // might even use self paths
        graph[a][b].push_back(c);
    }

    // if there more than 10 edges between u and v pop the longest ones
    for (const auto& [u, e]: graph) {
        for (const auto& [v, _]: e) {
            sort(graph[u][v].begin(), graph[u][v].end());

            while (graph[u][v].size() > k) {
                graph[u][v].pop_back();
            }
        }
    }

    // init dist
    const long long MAX = (long long)(1e9) * 100000LL;
    priority_queue<long long> IMAX;
    for (int i = 0; i < k; i++) {
        IMAX.push(MAX);
    }

    // try to use a pq instead of a multiset
    // max heap
    vector<priority_queue<long long>> dist(n + 1, priority_queue<long long>(IMAX));

    // min heap
    typedef pair<long long, long long> ll;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.emplace(0LL, 1);

    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (d >= dist[cur].top()) {
            continue;
        }

        // insert the new item
        // erase the last value then return it
        dist[cur].push(d);
        dist[cur].pop();
        if (cur == n && dist[cur].top() < MAX) {
            break;
        }

        for (const auto& [nxt, ws]: graph[cur]) {
            for (const auto& w: ws) {
                if (d + w < dist[nxt].top()) {
                    pq.emplace(d + w, nxt);
                }
            }
        }
    }

    vector<long long> res;
    while (!dist[n].empty()) {
        res.push_back(dist[n].top()); dist[n].pop();
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < k; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

