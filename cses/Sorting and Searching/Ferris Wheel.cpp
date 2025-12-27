#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // n is number of children and x is the max allowed weight
    int n, x;
    cin >> n >> x;

    multiset<int> a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.insert(b);
    }

    // each gondola can only have one or two children
    int res = 0;
    while (!a.empty()) {
        int cur = *prev(a.end());
        a.erase(prev(a.end()));

        auto it = a.upper_bound(x - cur);
        if (it != a.begin()) {
            a.erase(prev(it));
        }
        res++;
    }

    cout << res << endl;
}

