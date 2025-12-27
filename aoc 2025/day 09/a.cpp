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


typedef pair<long long, long long> ll;

long long siz(ll a, ll b) {
    long long x = abs(a.first - b.first) + 1;
    long long y = abs(a.second - b.second) + 1;
    return x * y;
}

int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    vector<ll> pos;
    while (getline(file, line)) {
        vector<string> s = split(line, ",");
        pos.emplace_back(stoll(s[0]), stoll(s[1]));
    }

    const int n = pos.size();
    long long best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            best = max(best, siz(pos[i], pos[j]));
        }
    }

    cout << best << endl;
}

