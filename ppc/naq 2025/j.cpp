#include <bits/stdc++.h>
using namespace std;


void solve() {
    int v;
    for (int i = 0; i < 100; i++) {
        cin >> v;
    }
    v %= 10;

    if (v == 0) {
        v = 10;
    }
    cout << v << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
