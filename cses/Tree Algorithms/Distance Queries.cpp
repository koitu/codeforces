#include <bits/stdc++.h>
using namespace std;

// we can also use a sprase table but I want to practice segtree for now
// use sparse table when we are working on the range queries stuff
struct segtree {
    vector<int> t;
    int n;

    segtree(const vector<int>& s) {
        n = s.size();
        t = vector<int>(n * 2 + 5, INT_MAX);

        for (int i = 0; i < n; i++) {
            t[i + n] = s[i];
        }

        for (int i = n - 1; i > 0; i--) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;

        int res = INT_MAX;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // idea: basically the same idea as Company Queries II
    // - pick 1 as the root
    // - find the LCA of the given nodes
    // - consider the distance from each node to the LCA
    //  - by tree properly there must be path and only one path
    //
    // the only thing now is to be careful not to backtrack

    int a, b;
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    map<int, vector<pair<int, int>>> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        q[a].emplace_back(b, i);
    }

    int time = 0;
    vector<int> start(n+1);
    vector<int> height(n+1);
    // vector<int> flatten;
    vector<int> fheight;

    auto dfs1 = [&](auto self, int cur, int pre, int h) -> void {
        start[cur] = time;
        height[cur] = h;

        // flatten.push_back(cur);
        fheight.push_back(h);
        time++;

        for (int nxt: g[cur]) {
            if (nxt == pre) {
                continue;
            }
            self(self, nxt, cur, h+1);

            // flatten.push_back(cur);
            fheight.push_back(h);
            time++;
        }
    };
    dfs1(dfs1, 1, 1, 0);

    segtree st(fheight);
    vector<pair<int, int>> res;
    vector<int> prev;

    auto dfs2 = [&](auto self, int cur, int pre) -> void {
        prev.push_back(pre);

        for (auto [oth, idx]: q[cur]) {
            int l = start[cur];
            int r = start[oth];
            if (r < l) {
                swap(l, r);
            }

            // find the height of the least common ansestor
            // find the distance from each thing to the root
            // then subtract the common path away
            const int lcah = st.query(l, r+1);
            res.emplace_back(idx, height[cur] + height[oth] - (lcah * 2));
        }

        for (int nxt: g[cur]) {
            if (nxt == pre) {
                continue;
            }
            self(self, nxt, cur);
        }

        prev.pop_back();
    };
    dfs2(dfs2, 1, 1);
    sort(res.begin(), res.end());

    for (auto [_, r]: res) {
        cout << r << endl;
    }
}

