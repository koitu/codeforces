#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long MOD = 1e9 + 7;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res = (res << 1) % MOD;
    }

    cout << res << endl;
}

