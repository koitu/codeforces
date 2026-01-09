#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    // idea: don't overcomplicate
    // - start from the end (put down all the traffic lights)
    // - then remove until there is one traffic light left
    // - at each step we check if the best length increases after removing that traffic light
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());











}

