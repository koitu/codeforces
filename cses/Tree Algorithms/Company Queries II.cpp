#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    map<int, set<int>> g;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        g[a].push_back(i);
    }

    vector<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        q.emplace_back(a, b);
    }


}

