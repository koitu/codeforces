#include <bits/stdc++.h>
using namespace std;
typedef tuple<long long, long long, long long> iii;


vector<string> split(const string &s, const string &de) {
    vector<string> res;

    size_t cur = 0;
    size_t nxt;
    while ((nxt = s.find(de, cur)) != string::npos) {
        res.push_back(s.substr(cur, nxt - cur));
        cur = nxt + de.size();
    }
    res.push_back(s.substr(cur));

    return res;
}


struct ds {
    vector<int> p;
    vector<int> s;

    ds(int n) {
        p = vector<int>(n);
        s = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int get(int i) {
        if (p[i] == i) {
            return i;
        }

        return p[i] = get(p[i]);
    }

    int size(int i) {
        return s[get(i)];
    }

    void merge(int i, int j) {
        int a = get(i);
        int b = get(j);

        if (a == b) {
            return;
        }

        if (s[a] > s[b]) {
            swap(a, b);
        }

        s[b] += s[a];
        p[a] = b;
    }
};

long long dist(iii a, iii b) {
    const long long x = get<0>(a) - get<0>(b);
    const long long y = get<1>(a) - get<1>(b);
    const long long z = get<2>(a) - get<2>(b);
    // no sqrt needed
    return x*x + y*y + z*z;
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    vector<iii> nodes;

    while (getline(file, line)) {
        vector<string> s = split(line, ",");
        nodes.emplace_back(stoll(s[0]), stoll(s[1]), stoll(s[2]));
    }

    const int n = nodes.size();
    vector<iii> d;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            d.emplace_back(dist(nodes[i], nodes[j]), i, j);
        }
    }
    sort(d.begin(), d.end());

    ds dis(n);
    // const int merge_n = 10;
    const int merge_n = 1000;
    for (int i = 0; i < merge_n; i++) {
        auto [di, ii, jj] = d[i];
        // cout << di << " " << ii << " " << jj << endl;
        dis.merge(ii, jj);
    }

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[dis.get(i)] = dis.size(i);
    }

    vector<pair<int, int>> p;
    for (auto [k, v]: m) {
        p.emplace_back(v, k);
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    // for (auto [k, v]: p) {
    //     cout << k << " " << v << endl;
    // }

    cout << p[0].first * p[1].first * p[2].first << endl;
}

