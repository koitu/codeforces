#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    typedef long long ll;
    typedef tuple<ll, ll, ll> lll;

    map<int, map<int, long long>> graph;
    long long a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        // one way
        if (!graph[a].count(b)) {
            graph[a][b] = INT_MAX;
        }
        graph[a][b] = min(graph[a][b], c);
    }

    // after discount and before discount
    vector<long long> dist_ad(n+1, LLONG_MAX);
    vector<long long> dist_bd(n+1, LLONG_MAX);

    priority_queue<lll, vector<lll>, greater<lll>> pq;
    pq.emplace(0LL, 0LL, 1);

    while (!pq.empty()) {
        auto [d1, d2, cur] = pq.top(); pq.pop();
        bool skip = true;

        if (d1 < dist_ad[cur]) {
            dist_ad[cur] = d1;
            skip = false;
        }

        if (d2 < dist_bd[cur]) {
            dist_bd[cur] = d2;
            skip = false;
        }

        if (skip) {
            continue;
        }
        for (auto [nxt, w]: graph[cur]) {
            if (dist_ad[nxt] > min(dist_ad[cur] + w, dist_bd[cur] + w / 2) ||
                dist_bd[nxt] > dist_bd[cur] + w) {
                pq.emplace(
                        min(dist_ad[cur] + w, dist_bd[cur] + w / 2),
                        dist_bd[cur] + w,
                        nxt);
            }
        }
    }

    // doesn't work...
    cout << dist_ad[n] << endl;

    // // another idea: store the largest weight instead
    // vector<long long> dist(n+1, LLONG_MAX);

    // priority_queue<lll, vector<lll>, greater<lll>> pq;
    // pq.emplace(0LL, 0LL, 1);

    // while (!pq.empty()) {
    //     auto [d, bw, cur] = pq.top(); pq.pop();
    //     if (d >= dist[cur]) {
    //         continue;
    //     }

    //     dist[cur] = d;
    //     for (auto [nxt, w]: graph[cur]) {
    //         if (w > bw) {
    //             // when the wieght is greater than the previously seen largest weight
    //             // recover the discount made and add the discounted new weight
    //             if (d + (bw+1)/2 + w/2 < dist[nxt]) {
    //                 pq.emplace(d + (bw+1)/2 + w/2, w, nxt);
    //             }

    //         } else if (d + w < dist[nxt]) {
    //             // when the weight is the less than the previously seen largest weight
    //             pq.emplace(d + w, bw, nxt);
    //         }
    //     }
    // }

    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " " << dist[i] << endl;
    // }
    // cout << endl;
    // cout << dist[n] << endl;
}

