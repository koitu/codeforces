#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> c;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        c.emplace_back(a, b, i);
    }
    sort(c.begin(), c.end());

    int best = 0;
    // priority_queue<int, vector<int>, greater<int>> pq;
    // for (int i = 0; i < n; i++) {
    //     auto [a, b, idx] = c[i];

    //     while (!pq.empty() && pq.top() < a) {
    //         pq.pop();
    //     }
    //     pq.push(b);
    //     best = max(best, (int)pq.size());
    // }

    // create n rooms
    set<int> rooms;
    for (int i = 1; i <= n; i++) {
        rooms.insert(i);
    }

    vector<int> res(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rooms_alloc;

    for (int i = 0; i < n; i++) {
        auto [a, b, idx] = c[i];

        // clear out the people from the current day
        while (!rooms_alloc.empty() && rooms_alloc.top().first < a) {
            rooms.insert(rooms_alloc.top().second);
            rooms_alloc.pop();
        }

        // allocate the room to the new customer
        int room = *rooms.begin();
        rooms.erase(rooms.begin());
        rooms_alloc.emplace(b, room);
        res[idx] = room;
        best = max(best, (int)rooms_alloc.size());
    }

    // print out the result
    cout << best << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

