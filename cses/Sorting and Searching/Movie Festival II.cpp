#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // sort by end values
    // then just take whenever we can (GREEDY)
    int a, b;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        c.emplace_back(b, a);
    }
    sort(c.begin(), c.end());

    int res = 0;
    multiset<int> e;

    // cout << endl;
    for (auto [r, l]: c) {
        if (!e.empty() && *e.begin() <= l) {
            auto it = prev(e.upper_bound(l));
            // cout << *it << " ";

            e.erase(it);
            e.insert(r);
            res++;

        } else if (e.size() < k) {
            e.insert(r);
            res++;
        }

        // cout << l << " " << r << endl;
    }

    cout << res << endl;
}

