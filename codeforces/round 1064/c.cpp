#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // vector<long long> r(n);
    typedef long long ll;
    list<ll> r;
    ll c;
    map<ll, vector<list<ll>::iterator>> m;
    for (int i = 0; i < n; i++) {
        // cin >> r[i];
        cin >> c;
        r.push_back(c);
        m[c].push_back(prev(r.end()));
    }

    // must be linear time for each solve()
    // at every step we want to take the pair with min val and remove the min value

    // idea: rather than removing the min val each time, what if we just replace it with the max of the two
    //  does this change the answer? yes, e.g. 3 1 2 1
   

    long long res = 0;
    queue<list<ll>::iterator> q1;
    queue<list<ll>::iterator> q2;
    for (auto [k, v]: m) {
        // for (int i: r) {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (r.size() <= 3) {
            break;
        }

        // remove duplicate values
        for (auto x: v) {
            if (r.size() <= 3) {
                break;
            }

            auto y = (next(x) == r.end()) ? r.begin() : next(x);
            auto z = (x == r.begin()) ? prev(r.end()) : prev(x);

            if (*y == *x || *z == *x) {
                res += *x;
                r.erase(x);
            } else {
                q1.push(x);
            }
        }

        // we won't iterate over lesser values (because they are already done)
        // so we can delete them
        while (!q1.empty() && r.size() > 3) {
            auto x = q1.front(); q1.pop();
            q2.push(x);

            auto y = (next(x) == r.end()) ? r.begin() : next(x);
            auto z = (x == r.begin()) ? prev(r.end()) : prev(x);

            if (*y < *x) {
                res += *x;
                r.erase(y);
            }
            if (*z < *x) {
                res += *x;
                r.erase(z);
            }
        }

        // remove duplicate values
        while (!q2.empty() && r.size() > 3) {
            auto x = q2.front(); q2.pop();
            auto y = (next(x) == r.end()) ? r.begin() : next(x);
            auto z = (x == r.begin()) ? prev(r.end()) : prev(x);

            if (*y == *x || *z == *x) {
                res += *x;
                r.erase(x);
            }
        }
    }

    // once there are 3 or less left just take the top n - 1 values
    vector<int> a;
    for (int i: r) {
        a.push_back(i);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++) {
        res += a[i];
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
