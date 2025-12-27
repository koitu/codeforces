#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;

    // for each 1 bit in n
    // we can take it an odd number of times
    // 
    // for each 0 bit in n
    // we can take it an even number of times
    if (k & 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;

    } else {
        // e.g.
        // 1101 can be split into 1010 0111
        // - invert the bits then add back the MSB
        // - turn the bits into all ones and remove the MSB
        //
        // 1011
        // only works for the zeros after the second MSB
        bitset<65> b(n);
        int mst = 0;
        for (int i = 0; i < 64; i++) {
            if (b[i]) {
                mst = i;
            }
        }

        int mst2 = -1;
        for (int i = mst - 1; i >= 0; i--) {
            if (b[i]) {
                mst2 = i;
                break;
            }
        }

        // cout << mst << " " << mst2 << endl;

        long long r = 1LL << mst;
        for (int i = mst2-1; i >= 0; i--) {
            r += 1LL << i;
        }

        cout << (n ^ r) << " ";
        cout << r << " ";

        for (int i = 2; i < k; i++) {
            cout << n << " ";
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
