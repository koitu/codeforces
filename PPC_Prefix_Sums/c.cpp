#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> vals(n + 1, 0);
    vector<int> a(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    sort(vals.begin(), vals.end(), greater<int>());

    int l, r;
    for (int i = 0 ; i < q; i++) {
        cin >> l >> r;

        a[l-1] += 1;
        a[r] -= 1;
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i-1];
    }
    sort(a.begin(), a.end(), greater<int>());

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (long long) a[i] * vals[i];
    }

    cout << res << endl;
}
