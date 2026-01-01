#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long long cur = 1LL;

    // suppose we can create every number to cur-1
    // then adding a[i] to we should be able to create every number to a[i] + cur - 1
    for (int i = 0; i < n; i++) {
        if (a[i] > cur) {
            break;
        }

        cur += (long long)(a[i]);
    }

    cout << cur << endl;
}

