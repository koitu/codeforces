#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    long long a;
    vector<long long> odd;
    vector<long long> even;
    even.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a & 1) {
            odd.push_back(a);
        } else {
            even.push_back(a);
        }
    }

    const int o = odd.size();
    const int e = even.size()-1;
    sort(odd.begin(), odd.end(), greater<long long>());
    sort(next(even.begin()), even.end(), greater<long long>());

    // largest number that can be made: take largest value from odd and all the values from even
    // other cases:
    //  - taking two values from odd makes zero
    //  - if odd.size() is even then the last one will be zero as we cannot make a even number
    for (int i = 1; i <= e; i++) {
        even[i] += even[i-1];
    }

    if (o == 0) {
        for (int i = 1; i <= n; i++) {
            cout << "0 ";
        }

    } else if (e == 0) {
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                cout << odd[0] << " ";
            } else {
                cout << "0 ";
            }
        }

    } else {
        // at least one odd and even value

        for (int i = 1; i < n; i++) {
            // try to take up to i-1 even values
            int ee = i - 1;

            // try to take the smallest odd number from odd
            int oo = 1;

            if (ee > e) {
                // take an odd amount of elements from odd
                // to do so move an even amount of elements from ee to oo
                // we will always have space to do so since i < n
                int diff = ee - e;
                if (diff & 1) {
                    diff++;
                }
                oo += diff;
                ee -= diff;
            }

            // at most oo will be greater than o by 1
            if (oo > o) {
                ee++;
                oo--;
            }

            if (oo & 1) {
                cout << odd[0] + even[ee] << " ";
            } else {
                cout << "0 ";
            }
        }

        if (odd.size() & 1) {
            cout << odd[0] + even[e] << " ";
        } else {
            cout << "0 ";
        }
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
