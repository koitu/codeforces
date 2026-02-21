#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, vector<int>> tree;
    int a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        tree[a].push_back(i);
    }

    vector<int> s(n+1, INT_MAX);
    auto dfs = [&](const auto& self, int i) {
        if (s[i] != INT_MAX) {
            return s[i] + 1;
        }

        int res = 0;
        for (int j: tree[i]) {
            res += self(self, j);
        }
        s[i] = res;
        return res + 1;
    };

    for (int i = 1; i <= n; i++) {
        // subtract itself
        cout << dfs(dfs, i) - 1 << " ";
    }
    cout << endl;
}

