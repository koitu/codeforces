#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    vector<pair<int, int>> s; // monotonic stack
    
    // larger but closer vs smaller but further
    // notice that when we find somethign smaller and closer we can override the previous -> use monotonic stack!
    for (int i = 0; i < n; i++) {
        cin >> a;

        while (!s.empty() && s.back().first >= a) {
            s.pop_back();
        }

        if (s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.back().second + 1 << " ";
        }
        s.emplace_back(a, i);
    }
    cout << endl;
}

