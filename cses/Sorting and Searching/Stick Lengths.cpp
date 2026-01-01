#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // get the median
    sort(a.begin(), a.end());
    long long med = a[n/2];

    long long res = 0LL;
    for (int i = 0; i < n; i++) {
        res += abs(med - a[i]);
    }

    cout << res << endl;
}

