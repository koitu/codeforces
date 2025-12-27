#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> mx_left(n);
    vector<int> mn_right(n);
    mx_left[0] = v[0];
    mn_right[n-1] = v[n-1];
    for (int i = 1; i < n; i++) {
        mx_left[i] = max(mx_left[i-1], v[i]);
        mn_right[n-1-i] = min(mn_right[n-1-(i-1)], v[n-1-i]);
    }

    vector<int> res;
    for (int i = 0; i < n ; i++) {
        if ((i == 0 || mx_left[i-1] <= v[i]) &&
            (i == n-1 || mn_right[i+1] >= v[i])) {
            res.push_back(v[i]);
        }
    }

    int m = min((int)res.size(), 100);
    cout << res.size() << " ";
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
