#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // subarray: contiguous ordered subset of an array
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }

//    // can we just choose any value that is not equal to previous two values?
//    // I think so, but need to be careful...
//    for (int i = n; i < n + k; i++) {
//        int d = 2;
//        while (i - d > 0 && a[i-d] == a[i-1]) {
//            d++;
//        }
//        int b = min(a[i-d], a[i-1]);
//        int c = max(a[i-d], a[i-1]);
//
//        if (b != 1) {
//            a.push_back(1);
//        } else if (c != n) {
//            a.push_back(n);
//        } else {
//            a.push_back((b + c) / 2);
//        }
//    }
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; i++) {
        p.emplace_back(b[i], i);
    }

    sort(p.begin(), p.end());

    
    for (int i = n; i < n + k; i++) {
        //cout << a[i] << " ";
        cout << p[i % p.size()].second << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
