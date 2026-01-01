#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.emplace_back(b, i+1);
    }
    sort(a.begin(), a.end());

    // get the number of increasing second values
    int res = 0;
    int cur = INT_MAX;

    vector<int> c(n);
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        if (a[i].second < cur) {
            res += 1;
        }
        cur = a[i].second;

        c[i] = cur;
        d[cur] = i;
    }

    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;

    int x, y, xi, yi;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        xi = d[x];
        yi = d[y];

        // looked at the solution for this part
        set<pair<int, int>> to_update;
        if (xi + 1 < n) {
            to_update.emplace(xi, xi+1);
        }
        if (xi - 1 >= 0) {
            to_update.emplace(xi-1, xi);
        }
        if (yi + 1 < n) {
            to_update.emplace(yi, yi+1);
        }
        if (yi - 1 >= 0) {
            to_update.emplace(yi-1, yi);
        }

        for (auto [k, v]: to_update) {
            res -= c[k] > c[v];
        }

        swap(c[xi], c[yi]);
        swap(d[x], d[y]);

        for (auto [k, v]: to_update) {
            res += c[k] > c[v];
        }

        cout << res << endl;

        // for (int i = 0; i < n; i++) {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
    }
}

