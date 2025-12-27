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

// backtracking with dp
map<string, set<string>> m;
map<string, long long> res;

// assume graph is a tree
// set<string> visited;

long long backtrack(const string &pos) {
    if (pos == "out") {
        return 1LL;
    }
    if (res.count(pos)) {
        return res[pos];
    }

    long long r = 0;
    for (const string &nxt: m[pos]) {
        r += backtrack(nxt);
    }
    return res[pos] = r;
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    while (getline(file, line)) {
        vector<string> c = split(line, " ");
        string a = c[0].substr(0, c[0].size()-1);
        for (int i = 1; i < c.size(); i++) {
            m[a].insert(c[i]);
        }
    }

    string start = "you";
    cout << backtrack(start) << endl;
}

