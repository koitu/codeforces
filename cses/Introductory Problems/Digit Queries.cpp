#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 1 to 9 -> 9 * 1
    // 10 to 99 -> 90 * 2
    // 100 to 999 -> 900 * 3
    // ...

    // 2**18 -> 262144
    // we can just brute force...
    // remember 2**20 -> about 1 million
    //vector<int> digits(1 << 19);
    //int i = 0;
    //int n = 1;
    //int end = 1 << 18;

    //while (i <= end) {
    //    for (char c: to_string(n)) {
    //        digits[i++] = c - '0';
    //    }
    //    n++;
    //}

    //int q, k;
    //cin >> q;
    //while (q--) {
    //    cin >> k;
    //    cout << digits[k-1] << endl;
    //}
    
    int q;
    long long k;

    cin >> q;
    while (q--) {
        cin >> k;

    }
}

