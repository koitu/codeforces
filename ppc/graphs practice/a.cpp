#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    // (x + y)^2 = x^2 + 2xy + y^2
    // (x + y)^3 = x^3 + 4x^2y + 4xy^2 + y^3

    // for (int y = 1; y <= 100; y++) {
    //     int v1 = (x + y) * (x + y);
    //     int v2 = v1 * (x + y);
    // }
    cout << 69 - x << endl;
}
