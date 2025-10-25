#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    vector<bool> b(n, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        b[a - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            cout << i + 1 << endl;
        }
    }
}

