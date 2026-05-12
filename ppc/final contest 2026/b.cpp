#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    deque<int> q;
    for (int i = 0; i < n; i++) {
        q.push_back(v[i]);
    }

    while (true) {
        for (const auto& i: q) {
            cout << i << " ";
        }
        cout << endl;

        bool sorted = true;
        int prev = INT_MIN;
        for (const auto& i: q) {
            if (prev > i) {
                sorted = false;
                break;
            }
            prev = i;
        }

        if (sorted) {
            break;
        }

        int a = q.front(); q.pop_front();
        int b = q.front(); q.pop_front();
        int c = q.back();

        // use is_sorted

        // keep pushing back the smaller of the first two elements (however if the first element is n then always send it to the back)
        // you can use indexing on deque

        if (a + 1 == b) {
            cout << "P";
            q.push_back(a);
            q.push_front(b);

        //} else if (a == b + 1) {
        //    cout << "SP";
        //    q.push_back(b);
        //    q.push_front(a);

        } else if (a == c + 1) {
            cout << "P";
            q.push_back(a);
            q.push_front(b);

        //} else if (b == c + 1) {
        //    cout << "SP";
        //    q.push_back(b);
        //    q.push_front(a);

        // } else if (a < b) {
        //     cout << "P";
        //     q.push_front(a);
        //     q.push_front(b);
        //     // cout << "SP";
        //     // q.push_back(b);
        //     // q.push_front(a);

        } else {
            cout << "SP";
            q.push_back(b);
            q.push_front(a);
        }

        // if (a > c && a < b) {
        //     cout << "P";
        //     q.push_back(a);
        //     q.push_front(b);

        // } else if (b > c) {
        //     cout << "S";
        //     q.push_front(a);
        //     q.push_front(b);

        // } else if (a < c && a > b) {

        // } else if (a < c && a < b) {
        //     cout << "P";
        //     q.push_back(a);
        //     q.push_front(b);
        // }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
