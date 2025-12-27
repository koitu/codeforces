#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    multiset<int> a;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a.insert(c);
    }

    // a stores tickets
    // b stores max price willing to pay for ticket
    for (int i = 0; i < m; i++) {
        cin >> c;
        auto it = a.upper_bound(c);
        if (it == a.begin()) {
            cout << -1 << endl;
        } else {
            cout << *prev(it) << endl;
            a.erase(prev(it));
        }
    }
}

