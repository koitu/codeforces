#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    set<int> visited;

    queue<pair<int, int>> q;
    q.emplace(n, 0);


    while (!q.empty()) {
        auto [v, d] = q.front(); q.pop();
        
        if (visited.count(v)) {
            continue;
        }
        visited.insert(v);

        if (v == k) {
            cout << d << endl;
            return;
        }

        int a = v / 2;
        int b = (v + 1) / 2;
        q.emplace(a, d + 1);
        q.emplace(b, d + 1);
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
