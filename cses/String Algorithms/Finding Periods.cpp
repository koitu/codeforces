#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    const int n = s.size();

    long long base = 100;
    long long mod = 1e9 + 7;

    vector<long long> pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow[i] = (pow[i-1] * base) % mod;
    }

    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = ((long long)(s[i-1] - 'a') + prefix[i-1] * base) % mod;
    }

    // thinking: we are able to compare substrings
    // how can we quickly check for a period of size i
    // we might be able to check for larger periods first, then if it is a multiple of a smaller one we get it for free
    // nesscary but not sufficient
    //
    // if we get a smaller period we get the larger ones for free?
    // just do the primes....??? no

    // simplfy: consider an array of integers instead of characters
    // - how can we find a cycle in that?
    // - idea: rolling hash?
    //
    // n + n/2 + n/3 + ... + 1 is in O(n log n)
    auto get_hash = [&](int l, int r) -> long long {
        long long res = (prefix[r] - ((pow[r - l + 1] * prefix[l-1]) % mod) + mod) % mod;
        return res < 0 ? res + mod : res;
    };

    for (int i = 1; i <= n; i++) {
        // cycle period
        bool res = true;

        int l = i + 1;
        while (l <= n) {
            int r = min(l + i - 1, n) - l;
            // cout << get_hash(1, 1 + r) << " " << get_hash(l, l+r) << endl;
            // cout << 1 << " " << 1 + r << " " << l << " " << l + r << endl;
            if (get_hash(1, 1 + r) != get_hash(l, l + r)) {
                res = false;
                break;
            }

            l += i;
        }

        // cout << endl;
        if (res) {
            cout << i << " ";
        }
    }
    cout << endl;
}

