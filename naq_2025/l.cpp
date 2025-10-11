#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    // each one of vals must be constructable from 3 (repeatable) numbers
    // idea: brute force?
    //  - for the first two try every number from 1 to 1000
    //  - 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
