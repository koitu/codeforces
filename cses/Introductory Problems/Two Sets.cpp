#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long tot = (n * (n + 1LL)) / 2LL;
    if (tot & 1LL) {
        // odd sum
        cout << "NO" << endl;
        return 0;
    }

    // we want to find if we can get a subset of 1..n to equal tot
    // we cannot perform a O(n^2) loop...
    // how do we keep track of all the subset sums
    //
    // we can either have k in the set or out of the set
    // 0-1 knapsack? I feel that there has got to be a faster way...
    tot /= 2;

    // feel pretty dumb
    // solution: add the numbers from n,..,1 until we are greater than tot
    //  - then remove the last added number and add the final filler number
    cout << "YES" << endl;

    long long cur = 0;
    long long i = 1;
    while (cur <= tot) {
        cur += i;
        i++;
    }

    int skip = cur - tot;
    cout << i - 2 << endl;
    for (int j = 1; j < i; j++) {
        if (j == skip) {
            continue;
        }
        cout << j << " ";
    }
    cout << endl;

    cout << n - (i - 2) << endl;
    cout << skip << " ";
    for (int j = i; j <= n; j++) {
        cout << j << " ";
    }
    cout << endl;
}

