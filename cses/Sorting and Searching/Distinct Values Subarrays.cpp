#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> cur;
    int i = 0;
    long long res = 0;
    for (int j = 0; j < n; j++) {
        while (cur.count(a[j])) {
            cur.erase(a[i++]);
        }
        cur.insert(a[j]);

        // number of ways we can pick the j and the values to the left
        // every sequenece will be made uniquely with the j-th value at the end
        res += (long long)(j - i + 1);
    }

    cout << res << endl;
}

