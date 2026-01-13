#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> freq;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        freq[a]++;
    }

    // if we only have a single copy of a number then we have two choices per subsequence: picked or not
    // if we have two copies then we have three choices: not picked, pick first, pick second
    // etc
    long long MOD = 1e9 + 7;
    long long res = 1;
    for (const auto [_, v]: freq) {
        res *= (long long)(v + 1LL);
        res %= MOD;
    }

    // need to remove the empty subsequence
    cout << (res-1LL + MOD) % MOD << endl;
}

