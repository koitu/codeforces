#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n--;

    long long res = 0;
    long long p;
    long long c;

    cin >> p;
    for (int i = 0; i < n; i++) {
        cin >> c;
        res += max(p - c, 0LL);
        p = max(p, c);
    }

    cout << res << endl;
}

