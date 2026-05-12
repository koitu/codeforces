#include <bits/stdc++.h>
using namespace std;


void solve() {
    string num;
    cin >> num;
    
    const int n = num.size();

    // 11111 -> 2111
    //
    // 12345
    // - 3345
    // - 15

    // case 1: we can get a two digit number
    // case 2: we can't get a two digit number

    int two_digit = -1;
    for (int i = 1; i < n; i++) {
        // our sum will always be less than the original
        // so we can just go from back to front rather than checking if it is ever greater
        if (num[i-1] - '0' + num[i] - '0' >= 10) {
            two_digit = i-1;

            if (num[i-1] - '0' + num[i] - '0' >= num[i-1] - '0' + (num[i] - '0') * 10) {
                break;
            }
        }
    }

    if (two_digit == -1) {
        cout << num[0] - '0' + num[1] - '0';
        for (int i = 2; i < n; i++) {
            cout << num[i];
        }
        cout << endl;

    } else {
        for (int i = 0; i < n; i++) {
            if (i == two_digit) {
                cout << num[i] - '0' + num[i+1] - '0';
                i++;
            } else {
                cout << num[i];
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
