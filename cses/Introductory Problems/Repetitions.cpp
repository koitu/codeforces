#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char c = '\0';
    char v;
    int cur = 0;
    int res = 0;

    do {
        cin.get(v); // get will read the atual next char from the input (including whitespace, which is ignored by operator>>)

        if (c != v) {
            res = max(res, cur);
            c = v;
            cur = 0;
        }
        cur++;

    } while (v != '\n');

    cout << res << endl;
}

