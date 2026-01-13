#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // sqrt decomp
    // sqrt(n) where n is 1e5 is about 1e3 and 1e8 (100 million) should be feasible in 1 second

    const int sq = ceil(sqrt(n));
    vector<set<int>> vals(sq);
    for (int i = 1, j = 0; i <= n; i++) {
        vals[j].insert(i);

        if (vals[j].size() >= sq) {
            j++;
        }
    }

    int cur = 0;
    int cur_left = vals[cur].size();
    int tot_left = n;
    auto it = vals[cur].begin();

    for (int i = 0; i < n; i++) {
        int kk = k % tot_left;

        // jump across segments until we get to the correct location
        // at max sqrt(n) jumps
        while (kk >= cur_left) {
            kk -= cur_left;

            cur = (cur + 1) % sq;
            cur_left = vals[cur].size();
            it = vals[cur].begin();
        }

        // move withint the segment
        while (kk-- > 0) {
            it = next(it);
            cur_left--;
        }

        // if we are at the end of a segment
        if (it == vals[cur].end()) {
            cur = (cur + 1) % sq;
            cur_left = vals[cur].size();
            it = vals[cur].begin();
        }

        // erase the current element
        cout << *it << " ";
        it = vals[cur].erase(it);
        if (it == vals[cur].end()) {
            cur = (cur + 1) % sq;
            cur_left = vals[cur].size();
            it = vals[cur].begin();
        }
        tot_left--;
    }

    cout << endl;
}

