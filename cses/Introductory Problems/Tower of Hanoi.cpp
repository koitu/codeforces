#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> res;

void hanoi(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }

    // shift n-1 disks from a to b using c
    hanoi(n-1, a, c, b);

    // shift nth disk from a to c
    res.emplace_back(a, c);
    // cout << a << " " << c << endl;

    // shift n-1 disks from b to c using a
    hanoi(n-1, b, a, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // looked at solution
    // idea:
    //  - shift n-1 disks from A to B using C as extra
    //  - move nth disk from A to C
    //  - shift n-1 disks from B to C using A as extra
    
    hanoi(n, 1, 2, 3);

    cout << res.size() << endl;
    for (auto [a, b]: res) {
        cout << a << " " << b << endl;
    }
}

