#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        res ^= b[i];
    }

    // consider that arrays start 1
    //
    // Ajisai can swap odd indices
    // Mai can swap even indices

    // Ajisai gets the xor of a
    // Mai get the xor of b
    
    // goal: odd number of 1s to win
    //       even number gets zero
    //
    // harder version: alternating dp?
    //      min-max: what is the largest value I can get with previous and this value
    //      would greedy work for this problem? maybe after considering the constant ones? (ones that do not change even after swapping)
    //
    // each player has and initial value and a set of pairs from which they take one and give the other away
    //
    // lets start with easier version

    //int odd = 0;
    //int even = 0;
    //for (int i = 0; i < n; i++) {
    //    if (a[i] != b[i]) {
    //        if ((i+1) & 1) {
    //            odd++;
    //        } else {
    //            even++;
    //        }
    //    }
    //}

    //// if there is an even number of 01s then the result is always the same
    //// this includes when odd == even
    //if ((odd + even) % 2 == 0) {
    //    cout << "Tie" << endl;
    //} else {
    //    if (odd > even) {
    //        cout << "Ajisai" << endl;
    //    } else {
    //        cout << "Mai" << endl;
    //    }
    //}

    // what does optimal play look like?
    // min-max: maximize your score while minimizing the opp
    //
    // what about order!
    // we can only counter a play that has already been done!

    //int aa = 0;
    //int bb = 0;

    //int odd = 0;
    //int even = 0;
    //for (int i = 0; i < n; i++) {
    //    int common = a[i] & b[i];
    //    aa ^= common;
    //    bb ^= common;
    //}

    //for (int i = 0; i < n; i++) {
    //    int common = a[i] & b[i];

    //    int a1 = aa ^ (a[i] ^ common);
    //    int a2 = aa ^ (b[i] ^ common);

    //    int b1 = aa ^ (b[i] ^ common);
    //    int b2 = aa ^ (a[i] ^ common);
    //    
    //    if (i % 2 == 0) {
    //        // Ajisai
    //        if (a1 - b1 > a2 - b2) {
    //            aa = a1;
    //            bb = b1;
    //        } else {
    //            aa = a2;
    //            bb = b2;
    //        }

    //    } else {
    //        // Mai
    //        if (b1 - a1 > b2 - b2) {
    //            aa = a1;
    //            bb = b1;
    //        } else {
    //            aa = a2;
    //            bb = b2;
    //        }
    //    }
    //}
    

    // bruh why am I so bad at XOR
    // solution
    //
    // easy:
    // - XOR all elements to get the XOR betweeen Ajisai and Mai's final scores
    // - if equal to zero then tie
    // - otherwise then whoever controls the last one flip wins
    // hard:
    // - same as easy but need to also consider the MST
    // - whoever controls the last flip of the MST wins


    if (res == 0) {
        cout << "Tie" << endl;
        return;
    }

    int mst = 0;
    while (res > 0) {
        mst++;
        res >>= 1;
    }
    mst--;

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] ^ b[i]) & (1 << mst)) {
            idx = i;
        }
    }

    if (idx % 2 == 0) {
       cout << "Ajisai" << endl;
    } else {
       cout << "Mai" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
