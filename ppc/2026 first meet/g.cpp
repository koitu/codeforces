#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<pair<int, long long>>> edges(n);
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edges[u-1].emplace_back(v-1, w);
        edges[v-1].emplace_back(u-1, w);
    }

    // d(i, j) = bitwise XOR of all weights of edges on the simple path form i to j
    // we want to find how many i < j such that
    // a[i] ^ a[j] = d(i, j)

    // brute force (even with seg tree) requires n^2 which is too much for n == 10^5


    // think about the properies of XOR
    // - commutative, assositive, self inverse
    // take p as the common parent of i and j
    // a[i] ^ a[j] = sum_{p to i} ^ sum_{p to j}
    //  -> sum_{root to i} ^ sum_{root to j} (since root to p cancel out)
    //
    // store a[i] ^ sum_{p to i} and find a[j] ^ sum_{p to j}

    vector<long long> path(n);
    auto dfs = [&](auto& self, int p, int c) -> void {
        for (auto [nxt, w]: edges[c]) {
            if (nxt == p) continue;

            path[nxt] = path[c] ^ w;
            self(self, c, nxt);
        }
    };
    path[0] = 0;
    dfs(dfs, 0, 0);

    map<long long, long long> freq;
    for (int i = 0; i < n; i++) {
        freq[path[i] ^ a[i]]++;
    }

    // minus out the self for i != j
    long long res = 0;
    for (int j = 0; j < n; j++) {
        res += freq[path[j] ^ a[j]] - 1LL;
    }

    // divide by 2 because we only want i < j
    cout << res/2LL << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
