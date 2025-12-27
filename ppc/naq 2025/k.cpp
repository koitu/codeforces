#include <bits/stdc++.h>
using namespace std;

void end(int i, int j) {
    // use two blocks to determine where in the quad the treasure is in
    int x, y;

    cout << "? " << i + 1 << " " << j << endl;
    cin >> x;

    cout << "? " << i << " " << j + 1 << endl;
    cin >> y;

    if (x == 0) {
        i--;
    }
    if (y == 0) {
        j--;
    }
//    if (x == 0 && y == 0) {
//        i--;
//        j--;
//    } else if (x == 0 && y == 1) {
//        i--;
//    } else if (x == 1 && y == 0) {
//        j--;
//    } else if (x == 1 && y == 1) {
//        // nothing
//    }

    cout << "! " << i << " " << j << endl;
}

void solve() {
    int res;

    // search quadrants
    cout << "? 2 2" << endl;
    cin >> res;
    if (res == 1) {
        end(2, 2);
        return;
    }

    cout << "? 2 4" << endl;
    cin >> res;
    if (res == 1) {
        end(2, 4);
        return;
    }

    cout << "? 4 4" << endl;
    cin >> res;
    if (res == 1) {
        end(4, 4);
        return;
    }

    // must be in last quad
    end(4, 2);
}

int main() {
    solve();
}
