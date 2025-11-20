#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // count the number of 2,5 pairs at the end
    //  - consider: number of numbers with 2 or 5 at end
    // count the number of zeros with number with zeros at the end
    //  - consider: number of numbers with 1 zero, 2 zero, 3...
    
    int res = 0;

    // // ends with 5 so we have 2*5
    // if (n % 10 >= 5) {
    //     res += 1;
    // }

    // // number of ways we can get 2 or 5
    // res += n / 10;

    // number of numbers with 1... zeros at the end
    // count the number of numbers with AT LEAST 1 zero, then 2 zeros, ...
    while (n > 0) {
        n /= 10;
        res += n;
    }

    // count the number of multiplies of 5 that exist in the n!
    // i.e. 5 * 2 = 10, 25 * 4 = 100, 125 * 8 = 1000
    // there always exists enough 2s (because they come before the 5s)
    for (int i = 5; i <= n; i *= 5) {
        int cur = n;
        while (cur > 0) {
            // ???
        }
    }


    cout << res << endl;
}

