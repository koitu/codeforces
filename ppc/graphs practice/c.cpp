#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    int a, b;
    map<int, vector<int>> g;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long MOD = 1e9 + 7;
    // wants to put cucumbers ai and bi next to each other
    for (int i = 1; i <= n; i++) {
        if (g[i].size() >= 3) {
            cout << -1 << endl;
            return;
        }
    }

    vector<bool> visited(n+1, false);
    stack<int> s;

    long long chains = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1 && !visited[i]) {
            visited[i] = true;
            int j = g[i][0];

            while (g[j].size() == 2) {
                visited[j] = true;

                int a = g[j][0];
                int b = g[j][1];

                if (visited[a] && visited[b]) {
                    cout << -1 << endl;
                    return;
                } else if (visited[a]) {
                    j = b;
                } else {
                    j = a;
                }
            }

            visited[j] = true;

            chains++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 2 && !visited[i]) {
            cout << -1 << endl;
            return;
        }
    }
    // cout << chains << endl;

    vector<long long> fac;
    vector<long long> pow2;
    fac.push_back(1);
    pow2.push_back(1);
    for (long long i = 1; i <= n*2; i++) {
        fac.push_back((fac.back() * i) % MOD);
    }
    for (long long i = 1; i <= n*2; i++) {
        pow2.push_back((pow2.back() * 2LL) % MOD);
    }

    long long other = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            other++;
        }
    }

    // cout << other << endl;
    cout << ((fac[other + chains] * pow2[chains]) % MOD) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
