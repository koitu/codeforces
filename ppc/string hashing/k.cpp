#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // note that 10! < 4e6
    vector<string> vals;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vals.push_back(s);
    }

    // we can arrange the strings in all the possible permutations
    // precompute the prefix and suffix hashes
    //



}
