#include <bits/stdc++.h>
using namespace std;


void solve(const int t) {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;

//    int a;
//    vector<int> v(n+1, 0);
//    vector<int> p(n+1, -1);
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        v[a]++;
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        p[a] = i;
//        v[a]--;
//    }
//
//    int res = 0;
//    int cur = 0;
//    vector<int> b;
//    vector<int> c;
//    for (int i = 0; i < n; i++) {
//        if (v[i] == 0) {
//            continue;
//        } else if (v[i] > 0) {
//            cur += v[i];
//        }
//    }


    int b;
    vector<int> temps(n); // current temps
    vector<int> findt(n+1, -1); // index to find a target temp
    map<int, vector<int>> nxt; // map of target temps to the indices that want to be adjusted to them

    for (int i = 0; i < n; i++) {
        cin >> temps[i];
        findt[temps[i]] = i;
//        cout << temps[i] << " ";
    }
//    cout << endl;

    bool valid = true;
    for (int i = 0; i < n; i++) {
        cin >> b;
//        cout << b << " ";
        if (b == temps[i]) {
            continue;
        } else if (b > temps[i]) {
            nxt[b].push_back(i);
        } else {
            valid = false;
            // cannot adjust a temp down
        }
    }
    if (!valid) {
        cout << -1 << endl;
        return;
    }
//    cout << endl;

    // move up the lower to greater
    // then continue with the rest
    //
    // iterate from the coldest indices that need to be adjusted
    vector<pair<int, int>> o;
    for (auto [k, v]: nxt) {
        if (findt[k] != -1) {
            for (int h: v) {
                o.emplace_back(findt[k] + 1, h + 1);
            }
        } else {
            cout << -1 << endl;
            return;
        }
    }


    cout << o.size() << endl;
    for (auto [k, v]: o) {
        cout << k << " " << v << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
}
