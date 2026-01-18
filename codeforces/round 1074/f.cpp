#include <bits/stdc++.h>
using namespace std;


struct segtree {
    const static int N = 1 << 19;
    int a[N];

    int n;
    segtree(const vector<int> &v) {
        a[0] = INT_MAX;

        n = v.size();
        for (int i = 0; i < n; i++) {
            a[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i * 2] ^ a[i * 2 + 1];
        }
    }

    void print() {
        for (int i = 1; i < 2*n; i++) {
            // newline on power of two
            if ((i & (i - 1)) == 0) {
                cout << endl;
            }
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int get_res(const int i, const int p) {
        int res = 0;
        int old = a[i + n];

        // get the result
        int t = 0;
        int ii = i + n;

        a[ii] = p;
        for (; ii > 1; ii >>= 1) {
            if ((ii & 1) && a[ii] <= a[ii^1]) {
                // (odd on the right) our cow is to the right
                res += (1 << t);
            }
            if (!(ii & 1) && a[ii] < a[ii^1]) {
                // (even on the left) our cow is to the left
                res += (1 << t);
            }
            t++;

            // merge the two cow stacks
            a[ii>>1] = a[ii] ^ a[ii^1];
        }

        // print();

        // reset
        ii = i + n;
        a[ii] = old;
        for (; ii > 1; ii >>= 1) {
            a[ii>>1] = a[ii] ^ a[ii^1];
        }

        return res;
    }
};


void solve() {
    int r, q;
    cin >> r >> q;

    const int n = 1 << r;
    // 2^n is the number of cows and q is the number of potions

    // what we need is like a XOR prefix sum
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree st(a);

    // the cows not given the potion will always take the same path
    // for the cow that was givne the potion we need to consider which side they are on and go up like a segment tree

    int b, c;
    for (int i = 0; i < q; i++) {
        cin >> b >> c;
        cout << st.get_res(b-1, c) << endl;
    }
    // cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
