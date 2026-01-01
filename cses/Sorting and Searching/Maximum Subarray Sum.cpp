#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i+1] = p[i] + a[i];
    }

    long long mn = p[0];
    long long best = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        best = max(best, p[i] - mn);
        mn = min(mn, p[i]);
    }

    cout << best << endl;
}

