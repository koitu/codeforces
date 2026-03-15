#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k, p, m;
    // n -> number of cards
    // k -> number of cards playable at a time
    // p -> initial post of win-cond
    // m -> total energy available
    cin >> n >> k >> p >> m;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i];

    int win_cond_cost = cards[p-1];
    cards[p-1] = INT_MIN;

    // idea: greedy always try to pick the win cond card (if possible then break and find how many times we can pick the card)
    //  - if can't then pick the cheapest card
    //
    // first cycle might be different
    // but later cycles will all be the same
    // binary search for most amount of cycles we can perform after the first cycle

    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(cards[i]);
    }
    for (int i = 0; i < k; i++) {
        pq.push(q.front()); q.pop();
    }

    int cost = win_cond_cost;
    while (pq.top() != INT_MIN) {
        int cur = pq.top(); pq.pop();
        cost += cur; 
        q.push(cur);

        pq.push(q.front()); q.pop();
    }

    m -= cost;
    if (m < 0) {
        cout << 0 << endl;
        return;
    }

    int res = 1;
    q.push(pq.top()); pq.pop();
    pq.push(q.front()); q.pop();

    cost = win_cond_cost;
    while (pq.top() != INT_MIN) {
        int cur = pq.top(); pq.pop();
        cost += cur; 
        q.push(cur);

        pq.push(q.front()); q.pop();
    }

    res += m / cost;
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
