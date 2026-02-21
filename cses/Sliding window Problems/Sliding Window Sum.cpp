#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // n -> number of elements
    // k -> size of window
    long long n, k;
    cin >> n >> k;

    // x -> first vlaue
    // a -> multiply by this
    // b -> add this
    // c -> mod by this
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> vals(n);
    for (int i = 0; i < n; i++) {
        vals[i] = x;
        x = (a * x + b) % c;
    }

    long long cur = 0LL;
    for (int i = 0; i < k; i++) {
        cur += vals[i];
    }

    long long res = cur;
    for (int i = k; i < n; i++) {
        cur -= vals[i-k];
        cur += vals[i];
        res ^= cur;
    }

    cout << res << endl;
}

