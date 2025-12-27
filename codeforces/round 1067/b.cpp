#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int v;
    map<int, int> m;
    for (int i = 0; i < 2*n; i++) {
        cin >> v;
        m[v]++;
    }

    // using the freq of elements in m
    // for each value we have three options:
    // - put in seq 1
    // - put part of it in seq 1
    // - put none of it in seq 1
    // seq 1 must sum to n but we want to maximize number of odd values in both
    //
    // idea:
    // - value is even -> try split to 2 odd values
    // - value is odd -> doesn't matter how is split, always adds one to res
    

    int cur = 0;
    int res = 0;
    int filler = 0;
    vector<int> even;
    for (auto [k, f]: m) {
        if (f & 1) {
            filler += f;
            res++;
        } else {
            even.push_back(f);
        }
    }

    // try to take 1 from each even value
    // even value -> 1 + v-1 two odd values
    for (int i = 0; i < even.size(); i++) {
        cur++;
        even[i]--;
        res += 2;
    }
    // this is always possible without overflowing

    // take twos until we can bridge the gap with filler
    // - case 1: filler == 0
    //  -> if we can collect 2s from cur to n then we are good
    // - case 2: filler > 0
    //  -> can collect 2s until at n or n-1 then fill rest
    if (cur < n && filler == 0 && ((n - cur) & 1)) {
        res -= 2;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
