#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // binary string of length n
    // Alice goes first, Bob goes second
    //
    // each turn a player picks a seq of indices such that characters are non-increasing and rearranges them in non-decreasing order
    // a move is valid iff it modifies the string s (zeros >= 1 and ones >= 1)
    //
    // first player who cannot make a valid move loses
    // output the player who wins with optimal play

    // ??? 0 1...1 0...0 1...1
    //      [ this much ]
    // can sort "this much" ones in a single step
    // if there are less than or equal to "this much" ones to the left and in "this much" then alice auto wins

    // e.g. 110101
    // alice can take 1 2 3 5 then bob has no valid moves
    
    string line;
    cin >> line;
    vector<int> v(n);
    vector<int> vv(n);

    for (int i = 0; i < n; i++) {
        v[i] = (line[i] == '1');
        vv[i] = (line[i] == '1');
    }
    sort(vv.begin(), vv.end());

    // want to check if the array is already sorted
    bool same = true;
    for (int i = 0; i < n; i++) {
        if (v[i] != vv[i]) {
            same = false;
            break;
        }
    }

    if (same) {
        cout << "Bob" << endl;
        return;
    }

    
    // what we are left with is a segment of 1s or 0s in the middle
    // this will fill up the zeros to the right of the segment with 1s
    int i = 0;
    int j = n - 1;
    vector<int> res;
    while (i < j) {
        if (!v[i]) {
            i++;

        } else if (v[j]) {
            j--;

        } else {
            // found the first 1 and last 0
            // swap them
            res.push_back(i+1);
            res.push_back(j+1);
            i++;
            j--;
        }
    }

    sort(res.begin(), res.end());
    cout << "Alice" << endl;
    cout << res.size() << endl;
    for (auto r: res) {
        cout << r << " ";
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
