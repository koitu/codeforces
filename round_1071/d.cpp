#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // 2**16 = 65536
    // sacred if it maximizes S(p)
    // we could maybe just about brute force this
    //
    // notice however that whenever the AND operation is performed we will always lose a 1
    // so the max sum is just 1 + 2 + ... + n
    //
    // find the lexically minimal permutation that does this
    // take 111...111 then bit shift it right each step
    
    const int m = (1 << n) - 1;
    set<int> v;

    for (int i = 0; i < n; i++) {
        // remove a space for the value and the zero
        int a = max(0, i - 1);
        int b = (1 << a) - 1;

        for (int j = 0; j <= b; j++) {
            int cur = (m >> i) + (j << (n - i + 1));
            v.insert(cur);
            cout << cur << " ";
        }
    }
    // while (cur > 0) {
    //     cout << cur << " ";
    //     v.insert(cur);
    //     cur >>= 1;
    // }

    for (int i = 0; i <= m; i++) {
        if (!v.count(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
