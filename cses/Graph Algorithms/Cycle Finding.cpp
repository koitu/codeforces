#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // bellman ford
    map<int, map<int, long long>> graph;
    int a, b;
    long long c;

    int early_result = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        // cycle on a single node
        if (a == b) {
            if (c >= 0) {
                continue;
            } else {
                early_result = a;
            }
            continue;
        }

        if (!graph[a].count(b)) {
            graph[a][b] = INT_MAX;
        }
        graph[a][b] = min(graph[a][b], c);
    }

    if (early_result) {
        cout << "YES" << endl;
        cout << early_result << " " << early_result << endl;
        return 0;
    }

    vector<tuple<int, int, long long>> edges;
    for (auto [u, e]: graph) {
        for (auto [v, w]: e) {
            edges.emplace_back(u, v, w);
        }
    }

    // ???
    // start from every node then see if we can make a negative cycle
    vector<long long> dist(n+1, 0LL);
    vector<long long> prev(n+1, 0LL);

    // make n - 1 jumps
    for (int i = 1; i < n; i++) {
        for (auto [u, v, w]: edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    // check for cycle
    for (auto [u, v, w]: edges) {
        if (dist[u] + w < dist[v]) {
            // // start should be part of a negative cycle
            // int start = v;

            // dist = vector<long long>(n+1, (long long)(n) * (long long)(INT_MAX));
            // prev = vector<long long>(n+1, 0LL);
            // dist[start] = 0;
            // prev[start] = start;

            // for (int i = 0; i < n; i++) {
            //     for (auto [u, v, w]: edges) {
            //         if (dist[u] + w < dist[v]) {
            //             dist[v] = dist[u] + w;
            //             prev[v] = u;
            //         }
            //     }
            // }

            // // dikjstra probably doesn't work because we could get stuck in another negative cycle
            // // typedef tuple<long long, int, int> lii;
            // // priority_queue<lii, vector<lii>, greater<lii>> pq;
            // // for (auto [nxt, w]: graph[start]) {
            // //     pq.emplace(w, nxt, start);
            // // }

            // // while (!pq.empty()) {
            // //     auto [d, cur, pre] = pq.top(); pq.pop();
            // //     if (dist[cur] <= d) {
            // //         continue;
            // //     }

            // //     dist[cur] = d;
            // //     prev[cur] = pre;
            // //     if (cur == start) {
            // //         break;
            // //     }
            // //     for (auto [nxt, w]: graph[cur]) {
            // //         if (dist[nxt] > d + w) {
            // //             pq.emplace(d + w, nxt, cur);
            // //         }
            // //     }
            // // }

            // cout << "start " << start << endl;
            // for (int i = 1; i <= n; i++) {
            //     cout << i << " " << prev[i] << endl;
            // }

            // vector<int> res;
            // res.push_back(start);
            // int cur = prev[start];
            // while (cur != start) {
            //     res.emplace_back(cur);
            //     cur = prev[cur];
            // }
            // res.emplace_back(start);
            // reverse(res.begin(), res.end());

            // cout << "YES" << endl;
            // for (auto i: res) {
            //     cout << i << " ";
            // }
            // cout << endl;
            // return 0;

            // // cout << "YES" << endl;

            // // vector<int> res;
            // // res.push_back(v);
            // // int cur = u;
            // // while (cur != v) {
            // //     res.push_back(cur);
            // //     cur = prev[cur];
            // // }
            // // res.push_back(cur);
            // // reverse(res.begin(), res.end());

            // // for (int i: res) {
            // //      cout << i << " ";
            // // }
            // // cout << endl;
            // // return 0;


            // idea: to find the actual loop we need to keep track of previous values to find the FIRST loop
            // for some problems the loop occurs after a couple of steps
            int cur = v;
            map<int, int> nxt;
            while (!nxt.count(cur)) {
                nxt[cur] = prev[cur];
                cur = prev[cur];
            }

            vector<int> res;
            res.push_back(cur);
            int start = cur;
            cur = nxt[cur];
            while (cur != start) {
                res.push_back(cur);
                cur = nxt[cur];
            }
            res.push_back(cur);

            reverse(res.begin(), res.end());
            cout << "YES" << endl;
            for (int i: res) {
                cout << i << " ";
            }
            cout << endl;

            
            return 0;
        }
    }

    // if (cur != 0) {
    //     cout << "YES" << endl;

    //     vector<int> res;
    //     int start = cur;
    //     res.push_back(cur);
    //     cur = prev[cur];

    //     while (cur != start) {
    //         res.push_back(cur);
    //         cur = prev[cur];
    //     }

    //     res.push_back(cur);
    //     reverse(res.begin(), res.end());

    //     for (int i: res) {
    //          cout << i << " ";
    //     }
    //     cout << endl;
    //     return 0;

    // } else {
    //     cout << "NO" << endl;
    // }
    cout << "NO" << endl;
}

