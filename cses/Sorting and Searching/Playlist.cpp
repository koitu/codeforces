#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int best = 0;

    queue<int> q;
    set<int> s;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (s.count(a)) {
            s.erase(q.front()); q.pop();
        }

        s.insert(a);
        q.push(a);
        best = max(best, (int)s.size());
    }

    cout << best << endl;
}

