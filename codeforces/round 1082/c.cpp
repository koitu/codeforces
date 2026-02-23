#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // to generate m + k integers
    // 1. get k and sequence of m integers (named x)
    // 2. if k == 0 then terminate, otherwise select 1 <= i <= x.size() and insert x[i] + 1 after element x[i]
    // 3. decrement k

    // find the length of the shortest sequence that could be given as input to generate a
    // problem: the things we are taking for the current sequence could be used to generate a different sequence
    // int res = 1;
    // long long l = a[0]+1;
    // long long r = a[0];
    // for (int i = 1; i < n; i++) {
    //     if (l <= a[i] && a[i] <= r + 1) {
    //         r = max(r, a[i]);
    //     } else {
    //         res++;
    //         l = a[i]+1;
    //         r = a[i];
    //     }
    // }

    // cout << res << endl;

    // idea: split into increasing branchs
    // then attempt to merge branchs
    // vector<pair<long long, long long>> branchs;
    // long long l = a[0];
    // long long r = a[0];
    // for (long long i = 1; i < n; i++) {
    //     if (a[i] == r || a[i] == r+1) {
    //         r = max(r, a[i]);
    //     } else {
    //         branchs.emplace_back(l, r);
    //         l = a[i];
    //         r = a[i];
    //     }
    // }
    // branchs.emplace_back(l, r);

    // long long res = 1;
    // long long m = branchs.size();
    // l = branchs[0].first;
    // r = branchs[0].second;
    // for (long long i = 1; i < m; i++) {
    //     long long nl = branchs[i].first;
    //     long long nr = branchs[i].second;

    //     if (l < nl && nl <= r) {
    //         r = max(r, nr);

    //     } else {
    //         res++;
    //         l = nl;
    //         r = nr;
    //     }
    // }

    // cout << res << endl;

    // :(
    // ???


    int res = 1;
    long long l = a[0];
    long long c = a[0];
    long long r = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == c + 1) {
            // going up
            c = a[i];
            r = max(r, c);

        } else if (l < a[i] && a[i] <= r) {
            // reset must be within a bound
            c = a[i];
            r = a[i];

        } else {
            // otherwise we need to create from another one
            res++;
            l = a[i];
            c = a[i];
            r = a[i];
        }
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
