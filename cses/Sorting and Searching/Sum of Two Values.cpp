#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int v;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (m.count(x - v)) {
            cout << m[x - v]+1 << " " << i+1 << endl;
            return 0;
        }
        m[v] = i;
    }

    cout << "IMPOSSIBLE" << endl;
}

