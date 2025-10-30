#include <bits/stdc++.h>
using namespace std;


long long fastexp(long long b, long long e, long long p) {
    long long res = 1;

    while (e > 0) {
        if (e & 1) {
            res = (res * b) % p;
        }
        b = (b * b) % p;
        e >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9 + 7;
    int n;
    cin >> n;

    // use the numbers from 1 to n to construct a sum half of the their sum
    int total = (n * (n + 1)) / 2;
    if (total % 2 == 1) {
        // odd so done
        cout << 0 << endl;
        return 0;
    }

    total /= 2;

    // dp number of ways to construct the the numbers 1...n, each time we iterate we include the next number
    vector<int> cur(total+1, 0);
    vector<int> nxt(total+1, 0);
    cur[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= total; j++) {
            nxt[j] = cur[j-i];
        }

        for (int j = 0; j <= total; j++) {
            cur[j] = (cur[j] + nxt[j]) % MOD;
            nxt[j] = 0;
        }
    }

    // we found all the ways to make total, but we acutally want the number of ways to make two equal sets
    // cur[total] is much too large even for long long or __int128 to hold
    // instead we want to find the modular inverse for 2 and multiply
    // fermat's little theorm: x^p = x mod p   ->   x^{p-2} = x^{-1} mod p   (using fast exp this isn't actually that hard)
    // egcd: ax + py = gcd(a, p)  (I forgot how to do this...)
    long long twoinv = fastexp(2, MOD - 2, MOD);
    long long res = cur[total];
    cout << (res * twoinv) % MOD << endl;
}

