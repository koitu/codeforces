#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    // per move we can choose
    // 1. remove one coin left and two coins right
    // 2. remove two coins left and one coin right
    // print if we can remove all the coins

    // thinking
    // - we can get to any multiple of 3
    // - after that we require one side to be n and the other to be 2n
    // - it doens't matter that order we perform the moves
    // - the min(# of 1, # of 2) will make up the base of 3s

    // idea
    // - find the difference between a and b
    // - make that n
    // - subtract n from the smaller and 2n from the larger
    // - (they should be equal now)
    // - how check that they are divisble by 3

    if (a > b) {
        swap(a, b);
    }

    // ensure a <= b
    int n = b - a;
    a -= n;
    b -= 2*n;

    if (a >= 0 && b >= 0 && a % 3 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) solve();
}

