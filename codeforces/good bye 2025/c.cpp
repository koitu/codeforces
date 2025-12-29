#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // long long res = LLONG_MIN;

    // if i is chosen then j++ and i = j-1
    // if j is chosen then j++
    // int i = 0;
    // int j = 1;

    vector<long long> p(n+1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }

    // // perform n-2 operations
    // for (int o = 1; o < n-1; o++) {
    //     // for children of i we want them to be positive
    //     // for children of j we want them to be negative
    //     // there will be one child left over

    //     // greedy? or dp?
    //     //
    //     // when child i is positive then choices are easy
    //     // - child j negative? -> add j
    //     // - child j positive? -> add i
    //     //
    //     // when child i is negative what to do?
    //     // - take them?
    //     // - tank the loss?
    // }


    // // for the last step
    // res += max(a[i], -a[j]);


    // long long cur = 0;
    // int i = 0;
    // int j = 1;
    // // 4 possible conditions
    // // - +, + -> take i
    // // - -, - -> take j
    // // - +, - -> take j
    // // - -, + -> take i or take all j

    // for (int o = 0; o < n-2; o++) {
    //     // if (a[i] < 0 && a[j] > 0) {
    //     //     // take the rest as negative
    //     //     res = max(res, cur - (p[n] - p[j]));

    //     //     // take a[i] as negative
    //     //     cur += a[i];
    //     //     i = j;
    //     //     j++;

    //     // } else if (a[j] < 0) {
    //     //     cur -= a[j++];

    //     // } else {
    //     //     cur += a[i];
    //     //     i = j;
    //     //     j++;
    //     // }

    //     // take the rest as negative
    //     res = max(res, cur - (p[n] - p[j]));

    //     // take a[i]
    //     cur += a[i];
    //     i = j;
    //     j++;
    // }

    // cur += max(a[i], -a[j]);
    // res = max(res, cur);


    // either take the first one or not
    long long cur = a[0]; // take the first one
    long long res = p[1] - p[n]; // don't take the first one

    // find a pos to exclude
    // we know we will take the first one so for the rest until the pos we exclude we can control pos or neg
    // the values after the pos we exclude is all neg
    for (int o = 1; o < n; o++) {
        // don't take o'th one
        // cout << cur << endl;
        res = max(res, cur + p[o+1] - p[n]);
        cur += abs(a[o]);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
