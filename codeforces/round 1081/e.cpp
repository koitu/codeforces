#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // idea: it doesn't matter which of a or b the values were originally part of
    // it just matters that we can balance a and b
    //
    // get the number of each element
    // try to get that number of each element in a (then b is already done)

    map<int, int> m;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        m[b[i]]++;
    }

    for (auto [k, v]: m) {
        if (v & 1) {
            cout << -1 << endl;
            return;
        }
        m[k] /= 2;
    }

    // now we want to go over the indices and pick items such that we match with m
    vector<int> to_swap;

    // skip the duplicates
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            m[a[i]]--;
        }
    }

    // issue: how to take such that if we need something in the future we are not preemp locking it away?
    // consider the current state of a (what a has in excess and what it needs)
    //
    // we know what to get rid of and what we want but I can't think of how....




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
