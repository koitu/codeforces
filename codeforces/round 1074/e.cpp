#include <bits/stdc++.h>
using namespace std;


void solve() {
    typedef long long ll;

    long long n, m, k;
    cin >> n >> m >> k;

    // inf long number line
    //
    // along the number line there are n robots and m spikes
    // i-th robot is at pos ai and i-th spike is at pos bi
    // if a robot is at a spike it dies

    // for each 1 <= i <= k
    // output how many robots are alive after the first i instructions are processed


    // idea: iterate over the instructions
    // - calcuate the max dist L and R from the starting poll after each first i instructions
    // - precalcuate for each robot their distance from a L and R spike to get on which instruction they will die on
    // - sum over :)

    ll a;
    vector<ll> robot;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        robot.push_back(a);
    }

    set<ll> spike;
    for (ll i = 0; i < m; i++) {
        cin >> a;
        spike.insert(a);
    }

    string inst;
    cin.ignore();
    // cin >> inst;

    if (m == 0) {
        for (ll i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }

    char c;
    ll cur = 0;
    ll best_l = 0;
    ll best_r = 0;
    vector<pair<ll, ll>> best_lr;
    while (cin.get(c) && c != '\n') {
        if (c == 'R') {
            cur++;
        } else if (c == 'L') {
            cur--;
        } else {
            continue;
        }

        best_l = max(best_l, -cur);
        best_r = max(best_r, cur);
        best_lr.emplace_back(best_l, best_r);
    }

    vector<ll> dead(k+1, 0); // amount of robots that die at this step
    for (ll i = 0; i < n; i++) {
        // find on which step this current robot will die
        ll ro = robot[i];
        auto it = spike.lower_bound(ro);

        // robots cannot begin on a spike
        ll l = (it == spike.begin()) ? INT_MIN : *prev(it);
        ll r = (it == spike.end()) ? INT_MAX : *it;
        //cout << ro << endl;
        //cout << l << " " << r << endl;

        // binary search to find the earliest the death can occur
        ll left = 0;
        ll right = k-1;
        ll best = k; // by default we say the robot makes it all the way through
        while (left <= right) {
            ll m = (left + right) / 2LL;

            auto [ml, mr] = best_lr[m];
            // cout << ml << " " << mr << endl;
            if ((ro - ml <= l) || (ro + mr >= r)) {
                best = m;
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        //cout << endl;

        dead[best]++;
    }

    // for (ll i = 0; i < k; i++) {
    //     cout << dead[i] << endl;
    // }
    // cout << endl;

    ll acc = 0;
    for (ll i = 0; i < k; i++) {
        acc += dead[i];
        cout << (n - acc) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
