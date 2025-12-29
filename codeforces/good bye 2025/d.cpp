#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a;
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.emplace_back(b, i+1);
    }

    // when m is greater than n/2 (rounded down) then impossible
    if (m > (n / 2)) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());

    // when two elfs have the same value they will both die
    // otherwise the greater one will survive with some lost health
    //
    // we need ALL elfs to attack another elf
    // and we want m elfs to be alive after the process

    // every elf needs to attack but cannot attack if it is already dead

    // is it possible to leave more than half of the elfs alive?
    // no, when an elf attacks another elf at most 1 elf is left alive
    //
    // for m > 0 we take the top m elfs then from the bottom m elfs, reduce until we reach m elfs
    //
    // for m = 0 we reduce the health of the greatest elfs to as low as possible then after killing the rest, hit the last one
    //
    //
    // it is guaranteed that all a[i] are DISTINCT!

    if (m == 0) {
        // for no elfs left we know that the greatest elf can one-shot the second greatest elf

        // gather elfs to hit the greatest elf until they can be killed by the second greatest
        // after that is done then pair up elfs until the second greatest

        vector<pair<int, int>> res;

        auto [h, idx] = a.back(); a.pop_back();
        int g = a.back().first;
        int i = 0;

        const int m = a.size();
        for (; i < m-1; i++) {

            res.emplace_back(a[i].second, idx);
            h -= a[i].first;

            if (h <= g) {
                i++;
                break;
            }
        }

        if (i == m - 1 && h > g) {
            cout << -1 << endl;
            return;
        }

        for (; i < m-1; i++) {
            res.emplace_back(a[i+1].second, a[i].second);
        }
        res.emplace_back(idx, a[m-1].second);

        for (auto [k, v]: res) {
            cout << k << " " << v << endl;
        }

    } else {
        reverse(a.begin(), a.end());

        // we can group up the sorted elfs into groups of m (leftmost group can be less than m)
        // every group attacks the group below it (destroying it) then there are m elfs left
        while (a.size() % m != 0) {
            a.emplace_back(0, 0);
        }

        int groups = a.size() / m;
        for (int i = groups-2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (a[((i+1)*m) + j].second > 0) {
                    cout << a[(i*m) + j].second << " " << a[((i+1)*m) + j].second << endl;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
