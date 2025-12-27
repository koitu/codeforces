#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

//    vector<int> s(n, 0);
//    vector<int> e(n, 0);

    int s, e;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
//        cin >> s[i] >> e[i];
        cin >> s >> e;
        m[s]++;
        m[e]--;
    }

    long long best = 0;
    long long cur = 0;
    for (const auto& [k, v] : m) {
        cur += (long long)v;
        best = max(best, cur);
    }

    cout << best << endl;

//    sort(s.begin(), s.end());
//    sort(e.begin(), e.end());
//
//    int i = 0, j = 0;
//    int cur = 0;
//    int best = 0;
//
//    while (i < n && j < n) {
//        if (s[i] == e[j]) {
//            i++;
//            j++;
//
//        } else if (s[i] < e[j]) {
//            cur++;
//            best = max(best, cur);
//            i++;
//
//        } else {
//            cur--;
//            j++;
//        }
//    }
//    cur += n - i;
//
//    // a ordered map instead
//    // difference array
//
//    cout << cur << endl;
}
