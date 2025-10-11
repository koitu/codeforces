#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long j = a[0];
    for (int i = 0; i < n; i++) j = max(j, (long long)a[i]);

    // score is 0
    // per operation 
    //  - choose an integer i and add ai to the your score
    //  - then set ai = max(0, ai - bi)
    //
    // what is the max score you can get in k operations

    // 1 billion operations -> 1 second!?
    // why not use a heap?

    // hint: binary search
    // idea: binary search on range of possible output
    //  - how to check?
    //  - think: n is pretty small (2e5 in total)
    //      - how much can we extract from each ai
    //      - can we maybe extract from than one op per time
    //      - maybe think about ops per score?

    // brute force: take the largest ai each time
    // smarter: use binary search to find how low ai goes

    long long i = 0;
    long long best = 0;
    while (i <= j) {
        long long m = (i + j) / 2;
        // only subtract if a[i] > m

        // times we can subtract until a[i] <= m
        long long v = 0;
        for (int z = 0; z < n; z++) {
            v += (long long)((max(a[z] - m, 0LL) + b[z] - 1)/b[z]);
            // think about adding some flexibility to the threshold
            // what if we can only add some values at the threshold (but not all...)
            // currently not working properly (issue with variables)
            //
            // instead find how many touch just above the threshold and give them the rest of the k
        }

        if (v <= k) {
            best = m;
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    cout << best << endl;

    // we now know how many times to get score from each a[i]
    // - we can use this to get the final value
    // - don't care if the final value is less then zero
    long long res = 0;
    for (int i = 0; i < n; i++) {
        // h -> number of times we reduce
        long long h = (max(a[i] - best, 0LL) + b[i] - 1)/b[i];

        // base -> final value of ai after we reduce h-1 times
        long long base = a[i] - b[i]*(h - 1);

        // get the result using the triangle
        res += base * h + ((h * (h + 1)) / 2) * b[i];
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
