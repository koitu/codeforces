#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // greedy
    // count the current number people seated and take out segments of 0s where new people can seat

    int res = 0;
    string s;
    cin >> s;
    vector<bool> done(n, false);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            res++;

            done[i] = true;
            if (i - 1 >= 0) {
                done[i-1] = true;
            }
            if (i + 1 < n) {
                done[i+1] = true;
            }
        }
    }

    // count the size of free segments
    // then divide by 3 rounded up (since each person can take up a maximum of 3 spots)
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (!done[i]) {
            cur++;
        } else {
            res += (cur + 2) / 3;
            cur = 0;
        }
    }
    res += (cur + 2) / 3;

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
