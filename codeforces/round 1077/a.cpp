#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // weird problem....
    // notice that it doesn't matter what the end values are
    //
    // idea: get the lineup of 1,...,n
    // start from n -> 1 -> n-1 -> 2 -> ...
    int i = 1;
    int j = n;
    bool turn = true;

    vector<int> res;
    while (i <= j) {
        if (turn) {
            res.push_back(i++);
            // cout << i++ << " ";
        } else {
            res.push_back(j--);
            // cout << j-- << " ";
        }

        turn = !turn;
    }

    reverse(res.begin(), res.end());
    for (int v: res) {
        cout << v << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
