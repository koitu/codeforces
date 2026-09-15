#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<long long> st;
    int n;

    segtree(const vector<long long>& init) {
        n = init.size();
        st = vector<long long>(n * 2 + 5);

        for (int i = 0; i < n; i++) {
            st[i + n] = init[i];
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

    // given rooted tree of n nodes
    //
    // we can two operations
    // - change the value of node s to x
    // - calculate the sum of values in the subtree of node s
    //
    // main idea this should just be segtree with update instruction
    // - store the value for node s in first[s] within the segtree
    // - to find the sum of nodes under s we consider first[s] to last[s]
    // - notice that every child c of s must have their first[c] within this range

    int n, q;
    cin >> n >> q;

    vector<long long> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    vector<vector<int>> g(n+1);
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // eular tour
    vector<long long> tour;
    vector<int> first(n+1);
    vector<int> last(n+1);
    auto dfs = [&](auto self, int cur, int par) -> void {
        tour.push_back(0);
        first[cur] = tour.size() - 1;

        for (int nxt: g[cur]) {
            if (nxt == par) continue;
            self(self, nxt, cur);
            // we only want to store when the tour first visits the node
            // then sum over when the the tour first visits to the value just before we stop visiting the current subtree
        }

        last[cur] = tour.size();
    };
    dfs(dfs, 1, 1);
    //for (int i = 1; i <= n; i++) {
    //    cout << first[i] << " ";
    //}
    //cout << endl;

    // setup the inital values
    for (int i = 1; i <= n; i++) {
        tour[first[i]] = vals[i-1];
    }

    //for (int i = 0; i < n; i++) {
    //    cout << tour[i] << " ";
    //}
    //cout << endl;

    // move to segtree
    segtree st(tour);

    long long x;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a == 1) {
            // update node b
            cin >> x;
            st.update(first[b], x);

        } else {
            // find the sum of nodes at the subtree rooted at b
            cout << st.find(first[b], last[b]) << endl;
        }
    }
}

