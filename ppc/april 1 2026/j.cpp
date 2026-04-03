#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x = 1;
    int y = 1e6;
    int best = 0;

    bool res;
    for (int i = 0; i < 23 && x <= y; i++) {
        int m = (x + y) / 2;

        cout << "? " << m << endl;
        cin >> res;
        if (res) {
            x = m + 1;
            best = m;
        } else {
            y = m - 1;
        }
    }

    cout << "! " << best << endl;;
}
