#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<char> table(n);
    for (int i = 0; i < n; i++) cin >> table[i];

//    // from every index get the index of the closest A from the left and closest B from the right
//    // out of range means there are none from that index
//    vector<int> a(n);
//    vector<int> b(n);
//
//    int c = -1;
//    for (int i = 0; i < n; i++) {
//        if (table[i] == 'B') {
//            c = i;
//        }
//        b[i] = c;
//    }
//
//    c = n;
//    for (int i = n - 1; i >= 0; i--) {
//        if (table[i] == 'A') {
//            c = i;
//        }
//        a[i] = c;
//    }

    // this reminds of the game of nim

    if (table[n-1] == 'A') {
        cout << "Alice" << endl;
        return;
    }

    // count the number of a's and b's at the ending ...B>AAABBB<
    // is a's are greater than Alice if b's are equal or greater than bob
    int a = 0;
    int b = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a > 0 && table[i] == 'B') {
            break;
        }

        if (table[i] == 'A') {
            a++;
        } else if (table[i] == 'B') {
            b++;
        }
    }

    if (a > b) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    // this is incorrect....
    // consider AAABABB
    // we should probably need to look at continuous segments of As and Bs
    // - then consider sacrafices?
    // - we can also jump to a different continuous segment...
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
}
