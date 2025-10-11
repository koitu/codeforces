#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<long long> a(n); // additional problems that can solved if team size i
    vector<long long> s(n); // number of problems each member can solve

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s.begin(), s.end(), greater<long long>());
    double best = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += s[i];

        best = max(best, (double)(a[i] + cur)/((double)(i + 1)));
    }

    cout << setprecision(16) << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
