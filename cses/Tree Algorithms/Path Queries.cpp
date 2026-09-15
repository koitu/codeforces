#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<long long> st;
    int n;

    segtree(const vector<long long> tour) {
        n = tour.size();
        st = vector<long long>(n * 2 + 5);

        for (int i = 0; i < n; i++) {
            st[i + n] = tour[i];
        }
        for (int i = n - 1; i > 0; i--) {
            st[i] = st[i * 2] + st[i * 2 + 1];
        }
    }

    void update(int s, long long x) {
        s += n;
        st[s] = x;
        for (; s > 1; s /= 2) {
            st[s / 2] = st[s] + st[s ^ 1];
        }
    }

    long long find(int l, int r) {
        l += n;
        r += n;
        long long res = 0;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) res += st[l++];
            if (r & 1) res += st[--r];
        }
        return res;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // two types of queries:
    // 1. change the value of node s to x
    // 2. calculate the sum of values on the path from the root to node s
    
    // this is probably another segtree problem...
    //
    // consider when will updating a node effect another node
    // - only when it is the parent!
    //
    // main idea: build segtree off the idea of
    // - positive values for the nodes we are in
    // - negative values for nodes we are abaout to exit
    // 
    // store the first and last of every node
    // - update s: update the first and last with the pos and negative of the value
    // - find s: perform segtree 0 to first[s] + 1

    int n, q;
    cin >> n >> q;

    vector<long long> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    int a, b;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // tour
    vector<long long> tour;
    vector<int> first(n + 1);
    vector<int> last(n + 1);
    auto dfs = [&](auto self, int cur, int pre) -> void {
        tour.push_back(0);
        first[cur] = tour.size() - 1;

        for (int nxt: g[cur]) {
            if (nxt == pre) continue;

            self(self, nxt, cur);
        }

        tour.push_back(0);
        last[cur] = tour.size() - 1;
    };
    dfs(dfs, 1, 1);

    // for (int i = 1; i <= n; i++) {
    //     cout << first[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << last[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        tour[first[i+1]] = vals[i];
        tour[last[i+1]] = -vals[i];
    }

    // query processing
    segtree st(tour);
    long long x;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a == 1) {
            // update
            cin >> x;
            st.update(first[b], x);
            st.update(last[b], -x);

        } else {
            // find
            cout << st.find(0, first[b] + 1) << endl;
        }
    }
}

