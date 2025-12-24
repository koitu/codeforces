#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // we can always choose the smallest element in the array
    // -> then just take x = every element in the array to map them all to 0
    //
    // we can't go beyond the second smallest element in the array as the smallest and second smallest can never be the same
    //
    // x1 = smallest
    // x2 = second smallest
    // k is in [x1, x2)
    //
    // use the smallest number as like a "core"
    // find the diff from every number to the core and make sure every diff is divisable by a number greater or equal to k
    //
    // binary search?
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    int core = a[n-1];
    while (a.back() == core) {
        a.pop_back();
    }

    // reverse(a.begin(), a.end());
    n = a.size();

    //for (int i = 0; i < n; i++) {
    //    a[i] -= core;
    //}

    // get the difference from the 2nd smallest element to the smallest element
    // our best k is currently core
    // in order to choose a larger k we need to difference between 2nd smallest and smallest to be greater than k
    // - this is minimal (otherwise we can't map 2nd smallest to smallest) (we can always choose a larger x to map the other values to smallest)
    cout << max(core, a[n-1] - core) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
