#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // ideas:
    // - two pointers (right pointer is where the current count has to end and left pointer is the max we can go left for the right pointer)
    // - find the number of subarrays with strictly greater than k distint values (sub from n * n-1)
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // note that we can always have less than k distint values :)
    long long res = 0;
    long long i = 0; // our current left limit
    long long j = 0; // our current right limit (used for counting)
    map<int, int> f; // store the distinct values and their number of copies

    // k is greater than 0
    for (; j < n; j++) {
        int cur = a[j];

        // if f doesn't already contain cur
        if (!f.count(cur)) {

            // AND f number of distinct values is already k
            while (f.size() == k) {

                // then move i and remove until we can fit a new distinct value
                int prev = a[i++];

                f[prev]--;
                if (f[prev] == 0) {
                    f.erase(prev);
                }
            }
        }

        f[cur]++;

        // get the distance from i to j (plus 1) because that is the number of steps we can move i (plus just the single element)
        res += j - i + 1LL;
    }

    cout << res << endl;
}

