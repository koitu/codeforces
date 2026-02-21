#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    map<int, set<int>> fgraph;
    map<int, vector<int>> bgraph;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        fgraph[a].insert(b);
        bgraph[b].push_back(a);
    }

    // topo sort is VERY useful when performing graph dp!
    // note that there are no directed cycles
    vector<int> done(n+1, 0);
    int time = 1;
    auto dfs = [&](auto self, int i) {
        if (done[i]) {
            return;
        }

        for (int j: fgraph[i]) {
            self(self, j);
        }

        done[i] = time++;
    };

    dfs(dfs, 1);

    // if (!done[n]) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        if (done[i]) {
            v.emplace_back(time - done[i], i);
        }
    }
    sort(v.begin(), v.end());

    const long long MOD = 1e9 + 7;
    vector<long long> dp(n+1, 0);
    dp[1] = 1;

    for (auto [_, i]: v) {
        for (int j: bgraph[i]) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
}


