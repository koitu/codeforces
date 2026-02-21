#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> p;
    p.push_back(0);

    long long a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        p.push_back(p.back() + a);
    }

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << p[r] - p[l-1] << endl;
    }
}

