#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    // n intgers representing the denominations of coins available initially
    // next m lines
    // - character c in {Q, X} and integer v <= 1e5
    // - c is the type of event and v is the vlaue of the event
    //  - Q query, output the minimum number of coins need to give ot exactly v
    //  - X out of coins of denomination v (cannot use coins of this type anymore)
    //
    // n <= 2000
    // m <= 1e5

    // we can work backwards

    // will all the coins be unique?

    vector<pair<int, int>> queries;

    int v;
    set<int> d;
    for (int i = 0; i < n; i++) {
        cin >> v;
        d.insert(v);
    }

    // store then reverse the queries
    string c;
    for (int i = 0; i < m; i++) {
        cin >> c >> v;
        // cout << c << " " << v << endl;
        if (c == "Q") {
            queries.emplace_back(0, v);
        } else if (c == "X") {
            d.erase(v);
            queries.emplace_back(1, v);
        }
    }
    reverse(queries.begin(), queries.end());
    
    // this will deal with being able to duplicate coins
    const int md = 1e5;
    vector<int> min_coin(md + 1, INT_MAX);
    min_coin[0] = 0;
    for (int step: d) {
        for (int i = 0; i <= md - step; i++) {
            if (min_coin[i] == INT_MAX) continue;
            min_coin[i+step] = min(min_coin[i] + 1, min_coin[i+step]);
        }
    }

    // run the queries in reverse
    // when we encounter a cc == 1 then we can insert back in step
    vector<int> results;
    for (auto [cc, vv]: queries) {
        if (cc == 0) {
            if (min_coin[vv] == INT_MAX) {
                results.push_back(-1);
            } else {
                results.push_back(min_coin[vv]);
            }
        } else {
            for (int i = 0; i <= md - vv; i++) {
                if (min_coin[i] == INT_MAX) continue;
                min_coin[i+vv] = min(min_coin[i] + 1, min_coin[i+vv]);
            }
        }
    }

    reverse(results.begin(), results.end());
    for (auto res: results) {
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
