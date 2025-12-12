#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 1 to 9 -> 9 * 1
    // 10 to 99 -> 90 * 2
    // 100 to 999 -> 900 * 3
    // ...

    // 10^18
    //
    // 9e18 -> long long max
    // 1.8e19 -> unsigned long long max
    typedef unsigned long long ull;
    
    int q;
    ull k;

    cin >> q;
    while (q--) {
        cin >> k;

        if (k < 10) {
            cout << k << endl;
            continue;
        }

        // find the range of numbers of k is in
        // - there are 'cur' numbers of 'len' length in this range
        ull len = 1;
        ull cur = 9;
        while (k > cur * len) {
            k -= cur * len;

            // there are ten times more numbers with len one longer
            len++;
            cur *= 10ULL;
        }

        // cout << k << " ";
        // cout << len << " ";

        // find the number that k lands on
        // get the starting number of the range
        ull v = 1;
        for (int i = 1; i < len; i++) {
            v *= 10ULL;
        }

        // offset from the number at the start of the range
        // then get the digit of the number using the index
        v += ((k - 1) / len);
        // cout << v << " ";
        string n = to_string(v);

        cout << n[(k - 1) % len] << endl;
    }
}

