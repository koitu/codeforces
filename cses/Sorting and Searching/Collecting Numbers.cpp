#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.emplace_back(b, i);
    }
    sort(a.begin(), a.end());

    // get the number of increasing second values
    int res = 0;
    int cur = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i].second < cur) {
            res += 1;
        }
        cur = a[i].second;
    }

    cout << res << endl;
}

