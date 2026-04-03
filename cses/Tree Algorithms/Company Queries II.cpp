#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int n;
    vector<int> t;

    segtree(const vector<int>& s) {
        n = s.size();

        // init segtree with values from n to n + (n - 1)
        t = vector<int>(n * 2 + 5, INT_MAX);
        for (int i = 0; i < n; i++) {
            t[i + n] = s[i];
        }

        // init the segtree internal nodes
        for (int i = n - 1; i > 0; i--) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    int query(int i, int j) {
        // find the min on the range [i, j)
        i += n;
        j += n;

        int res = INT_MAX;
        for (; i < j; i /= 2, j /= 2) {
            if (i & 1) {
                res = min(res, t[i++]);
            }
            if (j & 1) {
                res = min(res, t[--j]);
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a;
        g[a].push_back(i);
    }

    // vector<tuple<int, int, int>> q;
    map<int, vector<pair<int, int>>> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // q.emplace_back(a, b, i);
        q[a].emplace_back(b, i);
    }

    // Tree flattening: push back on an array each time you visit or exit a node
    //  - for each node: record it's height
    // Segtree: for each range we should know the max height (closest to root)
    // then each query of two employees is simply a range query on the flattened tree to the segtree
    //  - need to do some more thinking about it we get the first instance or the last instance of the node

    int time = 0;
    vector<int> start(n+1);
    vector<int> finish(n+1);
    vector<int> height(n+1);
    vector<int> flatten;

    auto dfs = [&](auto self, int i, int h) -> void {
        flatten.push_back(i);
        start[i] = time++;
        height[i] = h;

        for (int j: g[i]) {
            self(self, j, h+1);
            flatten.push_back(i); // we visit i again
            time++;
        }

        flatten.push_back(i);
        finish[i] = time++;
    };
    dfs(dfs, 1, 0);

    vector<int> fheight;
    for (int i: flatten) {
        fheight.push_back(height[i]);
    }
    segtree st(fheight);

    // for (int i: flatten) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i: fheight) {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<pair<int, int>> res;
    vector<int> prev;
    auto dfs2 = [&](auto self, int i, int h) -> void {
        prev.push_back(i);

        for (auto [j, idx]: q[i]) {
            int l = start[i];
            int r = start[j];
            if (l > r) {
                swap(l, r);
            }

            // get the parent at index of the parent height
            // - 0 -> root
            // - current height -> current node
            int ph = st.query(l, r+1);
            // cout << ph << endl;
            res.emplace_back(idx, prev[ph]);
        }

        for (int j: g[i]) {
            self(self, j, h+1);
        }
        prev.pop_back();
    };
    dfs2(dfs2, 1, 0);
    sort(res.begin(), res.end());

    for (auto [_, r]: res) {
        cout << r << endl;
    }
}

