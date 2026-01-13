#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> vals;
    for (int i = 1; i <= n; i++) {
        vals.insert(i);
    }

    auto it = vals.begin();
    for (int i = 0; i < n; i++) {
        it = next(it);
        if (it == vals.end()) {
            it = vals.begin();
        }

        cout << *it << " ";

        // erase will return the iterator after the just erased iterator
        it = vals.erase(it);
        if (it == vals.end()) {
            it = vals.begin();
        }
    }

    cout << endl;
}

