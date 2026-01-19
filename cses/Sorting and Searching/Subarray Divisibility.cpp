#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long SHIFT = INT_MAX * n; // c++ is not good at modulo for negative values

    // similar idea to subarray sum but now we considering everything basically mod n
    long long a;
    vector<long long> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        p[i] = (p[i-1] + a + SHIFT) % n;
    }

    long long res = 0;
    map<long long, long long> freq;
    freq[0] = 1;
    for (int i = 1; i <= n; i++) {
        // remember that for prefix sum we subtract from the current
        // what can we subtract from the current value to make equiv to 0 mod n -> search for the same value
        if (freq.count(p[i])) {
            // cout << p[i] << " " << i << endl;
            res += freq[p[i]];
        }

        freq[p[i]]++;
    }

    cout << res << endl;
}

