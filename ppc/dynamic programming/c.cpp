#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    vector<int> a(n);

    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == c) {
            result++;
        }
    }

    // for a segment that ends at dp[r]
    // is the maximum delta we can get for any l <= r
    //
    // want to figure out what choice of l to use
    // should contain maximize(# of a[r] - # of c)
    //
    // idea: search for every other dp[i] where a[i] == a[r]
    vector<int> dp(n, 0);


    
}
