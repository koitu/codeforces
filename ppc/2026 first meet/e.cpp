#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // keep track of the max element (this is what we will try to sum towards)
    // keep track of the sum (this is the sum)
    long long sum = 0;
    long long cur;
    long long mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> cur;
        mx = max(mx, cur);
        // cout << sum << " " << mx << endl;

        if (mx == (sum - mx + cur)) {
            cout << 'Y';
        } else {
            cout << 'N';
        }
        sum += cur;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
