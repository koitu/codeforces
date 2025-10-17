#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int os;
    int ms;
    cout << "1 " << 1 << " " << n << endl; // lol
    cin >> os;
    cout << "2 " << 1 << " " << n << endl;
    cin >> ms;

    // we simply want to find an index that splits the segment in half (then we can use the diff on the left and right to get the the indices)
    int i = 1;
    int j = n;
    while (i <= j) {
        if (i == j) {
            cout << "! " << i << " "  << j << endl;
            return;
        }

        // average (rounded down)
        int m = (i + j) / 2;

        int los;
        int lms;
        cout << "1 " << i << " " << m << endl;
        cin >> los;
        cout << "2 " << i << " " << m << endl;
        cin >> lms;

        int ros = os - los;
        int rms = ms - lms;

        int leftd = lms - los;
        int rightd = rms - ros;

        if (leftd > 0 && rightd > 0) {
            cout << "! " << m + 1 - leftd << " " << m + rightd << endl;
            return;
                
        } else if (leftd > 0) {
            os = los;
            ms = lms;
            j = m;

        } else {
            os = ros;
            ms = rms;
            i = m + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
