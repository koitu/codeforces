#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, x;
    cin >> n >> x;

    int a;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        cin >> a;
        p.emplace_back(a, i);
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());

    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = p[i].first;
    }


    // vector<long long> a(n);
    // string line;
    // long long val;
    // getline(cin, line);
    // istringstream iss(line);
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }

    // // using a regular map I get about 5 seconds on the largest cases so we should be better if we use a vector (as we can maintain it's sorted order manually)
    // // next time could try using a insertion hints?
    // unordered_map<long long, int> m;
    vector<long long> m;
    for (int i = 0; i < n; i++) {
        // cout << i << endl;
        // j and k should both be greater than i
        //
        // reduce problem to two sum
        long long goal = x - b[i];

        m.clear();
        for (int j = i + 1; j < n; j++) {
            // cout << j << endl;
            // if (m.count(a[j])) {
            auto it = lower_bound(m.begin(), m.end(), b[j]);
            if (it != m.end() && *it == b[j]) {
                // cout << i + 1 << " " << m[a[j]] + 1 << " " << j + 1 << endl;
                cout << p[i].second + 1 << " " << p[i + 1 + distance(m.begin(), it)].second + 1 << " " << p[j].second + 1 << endl;
                return 0;
            }

            // m[goal - a[j]] = j;
            m.push_back(goal - b[j]);
        }
    }


    cout << "IMPOSSIBLE" << endl;
    return 0;
}

