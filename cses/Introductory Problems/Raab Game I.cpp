#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // 4 2 1
    //
    // player 1:
    // 1 2 3 4
    //
    // player 2:
    // 1 2 3 4
    // 3 1 2 4
    
    // state both arrays at 1 to n
    // select a+b elements in the second array
    // after rolling b times
    //  - player 2 gets score b
    //  - player 1 gets score a+b-b = a
    
    if (a == 0 || b == 0) {
        // if either one of a or b is zero
        // we need them both to be zero to be a valid solution

        if (a == b) {
            cout << "YES" << endl;
            for (int k = 0; k < 2; k++) {
                for (int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }

        return;
    }

    // we know that both of a and b are greater than 0
    int m = a + b;
    if (m > n) {
        cout << "NO" << endl;
        return;
    }

    // now we roll the second array b times to give player 2 the score b
    // the rest of the roll will be the score of player 1 which is m-b = a

    // player 1
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;

    // player 2
    for (int i = 0; i < m; i++) {
        // 1 2 3
        // 3 1 2
        //
        // roll of b times means that for i=0 we should output i=-b
        cout << ((i + m - b) % m) + 1 << " ";
    }

    for (int i = m+1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) solve();
}

