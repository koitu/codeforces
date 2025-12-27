#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    // when s[i] is 0 then a[i] > b[i]
    // when s[i] is 1 then a[i] < b[i]
    char c;
    vector<bool> s(n);
    bool all_0 = true;
    bool all_1 = true;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s[i] = (c == '1');

        all_0 &= !s[i];
        all_1 &= s[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // x voters for A
    // y voters for B
    //
    // allocate at least p[i] voters per district
    // for districts s[i] == 0 we need one more a[i] then b[i]


    // lets count how many voters on each side are needed to get a majority
    int a = 0;
    int aa = 0;
    int b = 0;
    int bb = 0;
    for (int i = 0; i < n; i++) {
        int req = p[i] / 2 + 1;
        // cout << req << " ";
        if (s[i]) {
            b += req;
            bb += req;
            aa += req - 1;
        } else {
            a += req;
            aa += req;
            bb += req - 1;
        }
    }
    // cout << endl;

    // cout << a << b << endl;
    // don't need to actually solve?
    // check that we have the minimum amount of votes to win
    if (x >= a && y >= b) {
        // neccessary but not sufficient
        // if all the bits are on one side then make sure we have enough delta too

        // neccessary condition becomes sufficient if there is a mix of 0s and 1s
        if (!all_0 && !all_1) {
            cout << "YES" << endl;
            return;
        }

        // check that we can distribute the loser votes
        // cout << aa << " " << bb << endl;
        // cout << x << " " << y << endl;
        if ((all_0 && y - bb <= x - aa) || (all_1 && x - aa <= y - bb)) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
