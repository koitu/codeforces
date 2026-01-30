#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, set<int>> g;

vector<bool> visited;
vector<bool> done;
vector<int> parent;

int dfs(int p, int c) {
    if (done[c]) {
        return 0;
    }

    // somewhat hacky...
    // don't think I really need to return c (could probably just use false if =0 and true if >0)
    parent[c] = p;
    if (visited[c]) {
        return c;
    }
    visited[c] = true;

    for (int n: g[c]) {
        if (n == p) {
            continue;
        }

        int res = dfs(c, n);
        if (res) {
            return res;
        }
    }

    done[c] = true;
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // if we disallow backtracking (i.e. a -> b -> a)
    // then any traversal will include another city

    // oof I am pretty bad at graph theory....
    //
    // main idea: use something like topo sort to find a cycle
    // -> if there is a cycle it will be found by topo
    // -> although requires directed graph we will just disallow backtracking (same thing?)

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b) {
            continue;
        }

        g[a].insert(b);
        g[b].insert(a);
    }

    visited = vector<bool>(n+1, false);
    done = vector<bool>(n+1, false);
    parent = vector<int>(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int result = dfs(i, i);
        if (result && result != parent[result]) {
            vector<int> res;
            res.push_back(result);
            int c = parent[result];

            while (c != result) {
                res.push_back(c);
                c = parent[c];
            }
            res.push_back(c);

            cout << res.size() << endl;
            for (int j: res) {
                cout << j << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

