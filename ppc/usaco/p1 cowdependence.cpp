#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // harmonic series
    for (int k = 2; k <= n+1; k++) {
        // k is the window size

        map<int, int> m;
        int res = 0;

        for (int i = 0; i < k; i++) {
            m[a[i]]++;
        }

        for (int i = k; i < n; i++) {
            if (m.count(a[i-k])) {
                res++;
                m.erase(a[i-k]);
            }
            m[a[i]]++;
        }

        for (auto _: m) {
            res++;
        }
        cout << res << endl;
    }
}
