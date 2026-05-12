#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // - choose subarray (l, r)
    // - choose index j where l <= j <= r
    // - set all elements l to r to a[j]
    // - cost is r - l
    //
    // score is sum of elements plus cost of operations
    //
    // base idea: take the entire array then take the minimum value
    // - when it is not worth to take part of the array
    // - when we do take a part of the array we never look at it again?
    //
    // 2 3 3 2 3 -> 2 [ 2 2 2 2 ] -> 4 + 2 * 5 = 14
    //
    // we need to reduce one by 2 to break even 

    // idea: cost is r - l (NOT r - l + 1)

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
