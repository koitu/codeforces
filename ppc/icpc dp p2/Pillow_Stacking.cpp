#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, c;
    cin >> n >> c;

    // main question how many pillows
    // in what order
    // what pillows to use

    // from the first pillow how

    // notice that after 2**14 > 10,000 or at 14 pillows then if there is a value less than C then each new pillow will only add 1
    // idea: store an array of possible comfort values
    // - add the current comfort values to the array
    // - divide every comfort value by 2 (rounded up)
    // - create a new array and repeat the first step
    //
    // - after 64 times if the current state still has any possible values less then C then it is possible

    // store all the possible comfort values for a stack of n
    // - transition to new comfort values (truncate out values greater than C)
    // - if we hit exactly C then we are done
    // - after 64 times if there are still values less then C the we are also done

    // store al lthe pillow comfort values
    vector<long long> pillows(n);
    for (int i = 0; i < n; i++) cin >> pillows[i];

    vector<long long> cur;
    set<long long> nxt;

    cur.push_back(0);
    for (int t = 0; t < 64; t++) {
        for (int i = 0; i < cur.size(); i++) {
            for (int j = 0; j < n; j++) {
                long long val = cur[i] + pillows[j];
                if (val == c) {
                    cout << "YES" << endl;
                    return;
                } else if (val < c) {
                    nxt.insert(cur[i] + pillows[j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            pillows[i] = (pillows[i] + 1LL) / 2LL;
        }

        cur.clear();
        for (auto v: nxt) {
            cur.push_back(v);
        }
        nxt.clear();
        if (cur.empty()) {
            break;
        }
    }

    if (cur.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
