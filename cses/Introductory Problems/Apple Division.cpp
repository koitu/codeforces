#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

long long get_diff(int b) {
    long long res = 0;

    for (int i = 0; i < n; i++) {
        if (b & (1 << i)) {
            res += a[i];
        } else {
            res -= a[i];
        }
    }

    return abs(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a = vector<long long>(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // iterate over all the possible values from 0b0 to 0b111...111
    // 0 means set one
    // 1 means set two
    
    // brute force :)
    
    int m = 1 << n;
    long long best = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        best = min(best, get_diff(i));
    }

    cout << best << endl;
}

