#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> a;
    vector<int> b(m);
    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a.insert(c);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i] -= k;
    }

    sort(b.begin(), b.end());

    // greedy: assign each applicant to the smallest possible room
    int res = 0;
    for (int i = 0; i < m; i++) {
        int val = b[i];
        auto it = a.lower_bound(val);
        if (it != a.end() && *it <= val + 2*k) {
            a.erase(it);
            res++;
        }
    }

    cout << res << endl;
}

