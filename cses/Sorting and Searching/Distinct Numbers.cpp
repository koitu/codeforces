#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int v;
    set<int> vals;
    for (int i = 0; i < n; i++) {
        cin >> v;
        vals.insert(v);
    }

    cout << vals.size() << endl;
}

