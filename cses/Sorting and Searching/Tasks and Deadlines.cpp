#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // have n tasks: duration and deadline
    // will process tasks in some order one after another
    //
    // reward: maximize d - f (deadline - finishing time)
    //
    // ideas:
    // - finish the shortest task first
    // - since we get rewards for finishing a task early (that balances out a task being late) it is always the best to pick the shortest tasks

    vector<long long> dura(n);
    vector<long long> dead(n);
    vector<pair<int, int>> td;
    for (int i = 0; i < n; i++) {
        cin >> dura[i] >> dead[i];
        td.emplace_back(dura[i], i);
    }
    sort(td.begin(), td.end());

    long long time = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int idx = td[i].second;
        time += dura[idx];
        res += dead[idx] - time;
    }

    cout << res << endl;
}

