#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    // you are given a bracket sequence that is valid
    //
    // bracket seq a is better than seq b if
    // - b is a prefix of a and a != b; OR
    // - the first position where a[i] != b[i] has ai = ( and bi = )

    // remember that we can map ( -> +1 and ) -> -1 then
    // - bracket sequence is valid when total sums to 0 and there is no prefix that sums to less than 0
    // - seq a is better than seq b if by string cmp a > b
    //  - b is smaller and a prefix of a; OR
    //  - first location where a[i] != b[i] has ai = +1 and bi = -1

    // among all non-empty subsequences t of s
    // - find the max possible length of t such that t is better than s
    // - if it doesn't exist then output -1

    // the subsequence will always fail the first condition
    // instead we need to find some closing bracket location in s and replace it with an open bracket
    //
    // if possible won't the string always be just 2 less?

    // e.g. 1 1 -1 -1 1 -1 is impossible
    // e.g. 1 1 -1 1 1 -1 -1 -1 is possible
    // when removing the -1 1 we need to make sure that there exists a 1 later (otherwise we are not creating something greater)

    // notice that we must be able to find a -1 1
    // and we will always be able to remove it (since sum to zero and no prefix less than 0 is maintained)
    // after we just need to find a value of one to return n-2
    string line;
    cin >> line;

    // find the first instance of )(
    int i = 1;
    for (; i < n; i++) {
        if (line[i-1] == ')' && line[i] == '(') {
            break;
        }
    }

    // we want to find another ( that occurs after )(
    i++;

    if (i >= n) {
        cout << -1 << endl;
        return;
    }

    for (; i < n; i++) {
        if (line[i] == '(') {
            break;
        }
    }

    if (i >= n) {
        cout << -1 << endl;
        return;
    }

    cout << n - 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
