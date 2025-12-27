#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // rearrange
    // sum(ai, aj) = j - i + 1
    // p[r] - p[l-1] = r - (l - 1)
    // p[r] - p[l] = r - l
    // p[r] - r = p[l] - l
    // now count pairs (l, r) s.t. l < r
    //
    // map that stores p[i] - i
    
    vector<int> v(n + 1); // n >= 1
    v[0] = 0;
                      
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        v[i] = c - '0' + v[i-1];
    }

    long long res = 0;
//    for (int r = 1; r <= n; r++) {
//        for (int l = 0; l < r; l++) {
//            res += (v[r] - r) == (v[l] - l);
//        }
//    }

    // we want to count how many times p[r] - r occurs from 0, ..., r-1
    // store them in a map
    unordered_map<int, int> m;
    for (int i = 0; i <= n; i++) {
        res += (long long)m[v[i] - i];
        m[v[i] - i]++;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
