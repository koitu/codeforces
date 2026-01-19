#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    // subarray are contiguous -> can use prefix sum
    // use a map to store frequency of previously seen values

    long long a;
    vector<long long> p(n+1);
    p[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        p[i] = p[i-1] + a;
    }

    long long res = 0;
    map<long long, long long> f;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        // note that subarray cannot be empty as x > 0
        // search for the number of occurances of a num that when subtracted from p[i] makes x
        if (f.count(p[i] - x)) {
            res += f[p[i] - x];
        }

        f[p[i]]++;
    }

    cout << res << endl;
}

