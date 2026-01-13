#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    // idea: don't overcomplicate
    // - start from the end (put down all the traffic lights)
    // - then remove until there is one traffic light left
    // - at each step we check if the best length increases after removing that traffic light
    vector<int> a(n);
    set<int> signs;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        signs.insert(a[i]);
    }
    reverse(a.begin(), a.end());

    vector<int> result(n);
    int best = max(*signs.begin(), x - *prev(signs.end()));
    for (auto it = signs.begin(); next(it) != signs.end(); it = next(it)) {
        best = max(best, *next(it) - *it);
    }
    result[0] = best;

    // after looping n-1 times we will always be left with one item
    for (int i = 1; i < n; i++) {
        auto it = signs.find(a[i-1]);

        if (it == signs.begin()) {
            best = max(best, *next(it));

        } else if (it == prev(signs.end())) {
            best = max(best, x - *prev(it));

        } else {
            best = max(best, *next(it) - *prev(it));
        }
        signs.erase(it);

        result[i] = best;
    }

    for (int i = n-1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;
}

