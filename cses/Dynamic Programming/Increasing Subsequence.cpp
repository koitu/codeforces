#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // needs to be faster than O(n^2)
//    vector<int> dp(n, 1);

    // need some fast way to search for previous elements
    // want: a previous smaller than the current element with the largest dp
    // idea: some kind of stack where both the element and the increasing subsequence are increasing
    //  - notice we only push to the end when both the element and IS are greater than the last one
//    list<pair<int, int>> s;
//    map<int, list<pair<int, int>>::iterator> m;
//    s.push_back(make_pair(a[0], 1));
//    m[-a[0]] = prev(s.end()); // allows us to search for closest value LESS than current

    // idea: store the lowest value required to reach some value in dp
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    dp[1] = a[0];
    int j = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > dp[j]) {
            // when we find a value greater than anything in the array
            j++;
            dp[j] = a[i];

        } else {
            // find a value that a[i] is (strictly) less than and replace it with a[i]
            // if we only find values that are equal to it then continue
            int c = a[i];
            int x = 1;
            int y = j;
            int best = j;

            while (x <= y) {
                int m = (x + y) / 2;
                if (c <= dp[m]) {
                    best = m;
                    y = m - 1;
                } else {
                    x = m + 1;
                }
            }

            if (c < dp[best]) {
                dp[best] = c;
            }
        }
//        for (int z = 1; z <= j; z++) {
//            cout << dp[z] << " ";
//        }
//        cout << endl;
    }

    cout << j << endl;
}

