#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    // pick a idx and flip all idx other than it
    // want to make all the idx equal to 0

    // idea: other ways to look at it
    // - pick a idx and add one to every other place, want to make every idx a multiple of 2
    // - we want to sync up the indices, when we pick a index we are holding it back and making the other indices cycle one forward

    vector<bool> v;
    for (char c: s) {
        v.push_back(c == '1');
    }

    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            ones++;
        }
    }

    // if (count == 0) {
    //     cout << 0 << endl;

    // } else if (count == n - 1) {
    //     // a single 0
    //     cout << 1 << endl;
    //     for (int i = 0; i < n; i++) {
    //         if (!v[i]) {
    //             cout << i+1 << endl;
    //         }
    //     }

    // } else if (count & 1) {
    //     // if there are an odd number to sync up then the zeros will have only gone through an odd number of cycles to become 1
    //     cout << -1 << endl;

    // } else {
    //     cout << count << endl;
    //     for (int i = 0; i < n; i++) {
    //         if (v[i]) {
    //             cout << i+1 << " ";
    //         }
    //     }
    //     cout << endl;
    // }


    // another idea:
    // - let n be the number of places we pick
    // - each picked place gets n-1
    // - each non-picked place gets n
    // - we want for every place to be multiple of 2
    int zeros = n - ones;

    // pick all zeros -> works if zeros is odd
    // pick all ones -> works if ones are even
    //
    // if we pick two values and flip them both and the rest of the array stays the same
    // main idea: pick two values and flip them
    //
    // what if zeros is even and ones are odd?
    // only case we cannot do
    if (zeros & 1) {
        cout << zeros << endl;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                cout << i+1 << " ";
            }
        }
        cout << endl;

    } else if (ones == 0) {
        cout << 0 << endl;

    } else if (ones % 2 == 0) {
        cout << ones << endl;
        for (int i = 0; i < n; i++) {
            if (v[i]) {
                cout << i+1 << " ";
            }
        }
        cout << endl;

    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
