#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    // we want eaxctly k inversions
    // one inversion is a pair (i, j) where a[i] < a[j] while i > j

    // preforming one roll on an array of size n will add n-1 inversion
    // {5, 1, 2, 3, 4} -> 4 inversions
    // {5, 4, 1, 2, 3} -> 4 + 3 inversions
    // etc

    vector<int> res(n, 0);
    vector<int> used(n+1, false);

    for (int i = 0; i < n-1; i++) {
        int upd = n - i - 1;

        // cout << upd << endl;
        // cout << k << endl;
        cout << n - i << ": " << upd << " " << k << endl;
        if (upd <= k) {
            k -= upd;

            res[i] = n - i;
            used[n - i] = true;
        }
        // if (k == 0) {
        //     break;
        // }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    // TODO: inversions are not being done properly
    // consider 4 4
    // 4 1 2 3 -> 3
    //
    // need to rotate 1 2 or 2 3 to get 1
    // however we are just putting 2 in the index 2 :(

    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (!res[i]) {
            while (used[cur]) {
                cur++;
            }
            res[i] = cur++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

