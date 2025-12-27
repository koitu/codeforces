#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> res(51, 0);
    int j;
    for (int i = 0; i < n * 50; i++) {
        cin >> j;
        res[j]++;
    }

    vector<int> result;
    for (int i = 1; i <= 50; i++) {
        if (res[i] > n * 2) {
            result.push_back(i);
        }
    }

    if (result.size() == 0) {
        cout << -1;
    }
    for (int r: result) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
