#include <bits/stdc++.h>
using namespace std;


void solve() {
    vector<char> a;
    char c;
    while (cin.get(c) && c != '\n') {
        a.push_back(c);
    }

    // s must appear at least twice
    // each u must have two s next to it
    int res = 0;
    const int n = a.size();

    if (a[0] == 'u') {
        res++;
        a[0] = 's';
    }
    if (a[n-1] == 'u') {
        res++;
        a[n-1] = 's';
    }

    for (int i = 1; i < n-1; i++) {
        if (a[i] == 'u') {
            if (a[i+1] == 'u') {
                res++;
                a[i+1] = 's';
            }
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    char b;
    cin.get(b);
    while (t--) solve();
}
