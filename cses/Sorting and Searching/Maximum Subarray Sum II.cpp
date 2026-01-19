#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    // use prefix sum
    // iterate i
    // then keep a multiset with all the values between i-b and i-a
    // search in the multiset for the smallest value to be the largest subarray we can make with i as the last value

    vector<long long> p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }

    long long best = LLONG_MIN;
    multiset<long long> prev;
    int l = 0;
    int r = 0;
    for (int i = a; i <= n; i++) {
        while (l <= i - a) {
            prev.insert(p[l++]);
        }
        while (r < i - b) {
            prev.erase(prev.find(p[r++]));
        }
        // cout << i << " " << l << " " << r << endl;

        // prev should always contain at least one item
        best = max(best, p[i] - *prev.begin());
    }

    cout << best << endl;
}

