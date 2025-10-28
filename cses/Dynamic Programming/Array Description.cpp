#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const int MOD = 1e9 + 7;
    // we want to fill in all the zero values with values so difference between two values are at most 1
    // values we can use are 1 to m
    // gaps of 1 are pretty easy
    // how to deal with larger gaps?

    // idea: have a m x n array and have each point hold the number of possible ways to get there
    // better idea: just store the current m and next m
    
    vector<int> cur(m + 1, 0);
    // if we start with 0 then allow any position, else we start at one position
    if (a[0] == 0) {
        cur = vector<int>(m + 1, 1);
        cur[0] = 0;
    } else {
        cur[a[0]] = 1;
    }

    vector<int> nxt(m + 1, 0);

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            // if the value is zero then collect from all possible
            for (int j = 1; j <= m; j++) {
                nxt[j] = cur[j];

                if (j + 1 <= m) {
                    nxt[j] = (nxt[j] + cur[j+1]) % MOD;
                }
                if (j - 1 > 0) {
                    nxt[j] = (nxt[j] + cur[j-1]) % MOD;
                }
            }

        } else {
            // if the value is non-zero then only collect from 3
            int j = a[i];

            nxt[j] = cur[j];

            if (j + 1 <= m) {
                nxt[j] = (nxt[j] + cur[j+1]) % MOD;
            }
            if (j - 1 > 0) {
                nxt[j] = (nxt[j] + cur[j-1]) % MOD;
            }
        }

        swap(cur, nxt);
        nxt = vector<int>(m + 1, 0);
    }

    // sum over cur
    int res = 0;
    for (int i = 0; i <= m; i++) {
        res = (res + cur[i]) % MOD;
    }

    cout << res << endl;
}

