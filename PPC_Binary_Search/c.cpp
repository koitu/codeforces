#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;
    // n is too large to be an array
    // 1 billion bytes -> 1GB
    
    // function is like a valley
    long long i = 0;
    long long j = n - 1;
    long long best = n - 1;
    // we want to find the smallest idx where ai + ... + am > am+1 + an
    // check this is correct ^^^
    
    auto s = [&k](const long long m) {
        return k * m + (m * (m - 1LL))/2LL;
    };

    while (i <= j) {
        long long m = (i + j) / 2;
        long long mp = m + 1LL;

        long long left = s(mp)
        long long right = s(n) - left;

        if (left >= right) {
            best = m;
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    long long left = k * best + (best * (best - 1LL));
    long long right = k * n + (n * (n - 1LL))/2LL - left;
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
