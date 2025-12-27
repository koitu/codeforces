#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, int> p;

map<p, ull> states;
map<p, map<ull, vector<int>>> mm;

// don't think we need visited?
// every state should be increasing...
// set<int> visited;
ull MOD = 998244353;

ull traverse(ull prev, p cur) {
    p nxt = make_pair(prev + cur.first, cur.second);
    if (states.count(nxt)) {
        return states[nxt];
    }

    ull res = 1LL;
    if (mm.count(cur) && mm[cur].count(nxt.first)) {
        for (int a: mm[cur][nxt.first]) {
            res += traverse(cur.first, make_pair(nxt.first, a));
            res %= MOD;
        }
    }

    return states[nxt] = res;
}


void solve() {
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<ull> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e.emplace_back(a, b);
        mm[make_pair(v[a-1], a)][v[b-1]].push_back(b);
    }

    // some kind of graph dp?
    // start with m since each pair is a valid fib path
    ull res = 0;
    for (auto [c, d]: e) {
        res += traverse(v[c-1], make_pair(v[d-1], d));
        res %= MOD;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
