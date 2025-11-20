#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    // find the number of ways to place two pieces
    // subtract the number of ways to place two pieces attacking each other?
    // if we only allow knights to attack one way we can avoid double counting

    for (long long i = 1; i <= n; i++) {
        long long ii = i*i;

        // number of ways to place two knights on a board
        long long res = (ii * (ii-1LL)) / 2;

        // there are 4 knight "connections" that could be made
        // 1    222 33  44
        // 111  2   3    4
        //          3    4
        res -= 4LL * (max(0LL, i - 2LL) * max(0LL, i - 1LL));

        cout << res << endl;
    }
}

