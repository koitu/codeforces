#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a;
    int b, c;
    for (int i = 0; i < n; i++) {
        cin >> b >> c;
        a.emplace_back(b, c);
    }
    sort(a.begin(), a.end());

    int res = 0;
    multiset<int> s;

    for (int i = 0; i < n; i++) {
        auto [l, r] = a[i];
        s.insert(r);
        while (*s.begin() < l) {
            s.erase(s.begin());
        }
        res = max(res, (int)s.size());
    }

    cout << res << endl;

    // smarter solution:
    // - take the arrival event as +1
    // - take the leave event as -1
    // - sort then iterate over and return the highest value we reached
}

