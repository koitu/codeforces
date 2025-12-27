#include <bits/stdc++.h>
using namespace std;


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



int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    vector<pair<long long, long long>> rs;
    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        vector<string> r = split(line, "-");
        rs.emplace_back(stoll(r[0]), stoll(r[1]));
    }

    while (getline(file, line)) {
        // NOP
    }

    const int n = rs.size();
    sort(rs.begin(), rs.end());

    long long l = rs[0].first;
    long long r = rs[0].second;
    vector<pair<long long, long long>> mr;
    for (int i = 1; i < n; i++) {
        auto [ll, rr] = rs[i];

        if (ll <= r) {
            r = max(r, rr);
        } else {
            mr.emplace_back(l, r);
            l = ll;
            r = rr;
        }
    }
    mr.emplace_back(l, r);

    long long result = 0;
    for (auto [ll, rr]: mr) {
        result += rr - ll + 1LL;
    }

    cout << result << endl;
}

