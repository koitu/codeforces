#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // separate into increasing segments
    // for each of these segments we connect the lowest value to every other value in the segment
    vector<int> p(n);
    vector<bool> visited(n, false);
    vector<pair<int, int>> nxt;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        nxt.emplace_back(p[i], i);
    }
    sort(nxt.begin(), nxt.end(), greater<pair<int, int>>());

    // connect the lesser to the greater
    // then connect the greater to the least (seen so far)
    int cur_s = nxt[0].first;
    for (int i = 0; i <= nxt[0].second; i++) {
        cur_s = min(cur_s, p[i]);
        visited[i] = true;
    }

    for (int i = 1; i < n; i++) {
        auto [k, v] = nxt[i];
        if (visited[v]) {
            continue;
        }

        if (k < cur_s) {
            // there is nothing to connect back to
            // we want to connect this 2nd greatest value to the smallest value connected to the greatest value
            cout << "No" << endl;
            return;
        }

        for (int j = v; j >= 0; j--) {
            if (visited[j]) {
                break;
            }
            visited[j] = true;
            cur_s = min(cur_s, p[j]);
        }
    }

    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
