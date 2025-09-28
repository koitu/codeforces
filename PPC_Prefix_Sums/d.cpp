#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // iterate over the prefix sum array
    // then subtract the smallest value we saw before (that is less than 0), that is our current largest subarray sum
    long long best = INT_MIN;
    long long pst = 0;
    long long cur = 0;
    long long v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        cur += v;
        best = max(best, cur - pst);
        pst = min(pst, cur);
    }

    cout << best << endl;
}
