#include <bits/stdc++.h>
using namespace std;


struct segtree {
    const static long long MOD = 1e9 + 7;
    const static long long N = 4e5;

    long long a[N]; // set to all zeros
    int n;

    segtree(const int n) : n(n) {
        memset(a, 0LL, sizeof(a));
    }

    void print() {
        for (int i = 1; i < 2*n; i++) {
            if ((i & (i - 1)) == 0) {
                cout << endl;
            }
            cout << a[i] << " ";
        }
        cout << endl;
    }

    long long query(int l, int r) {
        long long res = 0;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = (res + a[l++]) % MOD;
            if (r & 1) res = (res + a[--r]) % MOD;
        }

        return res;
    }

    void update(int i, long long v) {
        i += n;
        a[i] = (a[i] + v) % MOD;

        for (; i > 1; i >>= 1) {
            a[i>>1] = (a[i] + a[i^1]) % MOD;
        }
        // print();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // coordinate compression then use segtree
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> b(a.begin(), a.end());
    map<int, int> c;
    int idx = 0;
    for (auto d: b) {
        c[d] = idx++;
    }

    // get the number of sequences with final value less than cur
    // at that number to cur (indicates how many more sequences we have)
    segtree st(b.size());
    for (int i = 0; i < n; i++) {
        int cur = c[a[i]];
        // cout << i << " " << cur << endl;
        st.update(cur, st.query(0, cur) + 1LL);
    }

    cout << st.query(0, b.size()) << endl;
}

