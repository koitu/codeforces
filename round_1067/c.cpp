#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // two considerations:
    // - what is the state of the array?
    // - which of the values in b is the largest

    typedef long long ll;

    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // idea: think of the delta
    // - whatever Alice does, Bob can undo
    // - does it ever make sense for Alice to make a move different than Bob's optimal?
    //  - assume no, I think?

    // so for now lets get the maximum non-empty subarray sum (along with max b along it)
    // - if k is even then just return it
    // - if k is odd then find the best value from b to add
    
    vector<ll> p(n+1, 0);
    for (int i = 0; i < n; i++) {
        p[i+1] = p[i] + a[i];
    }

    long long best = LLONG_MIN;
    if (k & 1) {
        // start from the end
        // keep track of the max value seen in a
        // notice that taking the current value in b will boost the later values by the same amount
        //
        // monotonic stack of decreasing values
        // once we reach it then pop

        stack<ll> s_val;
        stack<int> s_idx;

        s_val.push(0);
        s_idx.push(0);

        for (int i = 1; i <= n; i++) {
            if (p[i] < s_val.top()) {
                s_val.push(p[i]);
                s_idx.push(i);
            }
        }

        long long mx = LLONG_MIN;
        for (int i = n; i >= 1; i--) {
            if (s_idx.top() >= i) {
                s_val.pop();
                s_idx.pop();
            }

            mx = max(mx, p[i]);
            best = max(best, mx + b[i-1] - s_val.top());
        }

    } else {
        long long mn = 0;
        for (int i = 1; i <= n; i++) {
            best = max(best, p[i] - mn);
            mn = min(mn, p[i]);
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
