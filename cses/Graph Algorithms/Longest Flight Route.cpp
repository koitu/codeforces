#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    map<int, set<int>> fgraph;
    map<int, set<int>> bgraph;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        fgraph[a].insert(b);
        bgraph[b].insert(a);
    }

    // map<int, vector<int>> graph;
    // for (auto [i, s]: graph_temp) {
    //     for (auto j: s) {
    //         graph[i].push_back(j);
    //     }
    // }

    // // there are no directed cycles
    // typedef tuple<int, int, int> iii;
    // priority_queue<iii> q; // dist, pre, cur
    // q.emplace(0, 1, 1);

    // vector<int> prev(n + 1);
    // vector<int> dist(n + 1, -1);

    // while (!q.empty()) {
    //     auto [d, pre, cur] = q.top(); q.pop();
    //     if (d <= dist[cur]) {
    //         continue;
    //     }

    //     prev[cur] = pre;
    //     dist[cur] = d;
    //     for (int nxt: graph[cur]) {
    //         if (d + 1 > dist[nxt]) {
    //             q.emplace(d + 1, cur, nxt);
    //         }
    //     }
    // }

    // if (dist[n] == -1) {
    //     cout << "IMPOSSIBLE" << endl;
    //     return 0;
    // }

    // vector<int> res;
    // int cur = n;
    // while (cur != prev[cur]) {
    //     res.push_back(cur);
    //     cur = prev[cur];
    // }
    // res.push_back(cur);
    // reverse(res.begin(), res.end());
    // 
    // cout << res.size() << endl;
    // for (int r: res) {
    //     cout << r << " ";
    // }
    // cout << endl;

    // the above actually is too slow
    // need to use dp with topo sort (DAG)
    //
    // main idea: use topo sort to label the nodes (reverse the labels)
    //   then use dp[i] = max distance to reach node i

    // don't need visited because we were insured that there is no cycle (graph is a DAG)
    // vector<bool> visited(n+1, false);
    vector<bool> done(n+1, false);
    vector<int> done_time(n+1);
    int time = 0;

    auto dfs = [&](auto self, int i) {
        if (done[i]) {
            return;
        }

        for (int j: fgraph[i]) {
            self(self, j);
        }

        done_time[i] = time++;
        done[i] = true;
    };

    // for (int i = 1; i <= n; i++) {
    //     dfs(i);
    // }
    // only go to the nodes that can be reached from 1
    dfs(dfs, 1);

    if (!done[n]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        if (done[i]) {
            // reverse the order
            v.emplace_back(time - done_time[i], i);
        }
    }
    sort(v.begin(), v.end());
    // for (auto [i, j]: v) {
    //     cout << i << " " << j << endl;
    // }

    vector<int> prev(n+1, 0);
    vector<int> dist(n+1, 0);
    set<int> visited;

    for (auto [_, i]: v) {
        // there must be at least one node that leads to this (by the property of the topo sort)
        int best = 0;
        int p = 0;

        for (int j: bgraph[i]) {
            // NOTE: don't acutally need visited due to prop of topo sort!
            if (visited.count(j) && dist[j] > best) {
                best = dist[j];
                p = j;
            }
        }
        dist[i] = best + 1;
        prev[i] = p;
        visited.insert(i);
    }

    vector<int> res;
    int c = n;
    while (c != 1) {
        res.push_back(c);
        c = prev[c];
    }
    res.push_back(c);

    reverse(res.begin(), res.end());
    cout << dist[n] << endl;
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
}

