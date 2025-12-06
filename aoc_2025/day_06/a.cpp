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

vector<string> splitws(const string &s) {
    vector<string> res;

    stringstream ss(s);
    string v;
    while (ss >> v) {
        res.push_back(v);
    }
    return res;
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    vector<vector<string>> m;
    while (getline(file, line)) {
        m.push_back(splitws(line));
    }

    vector<string> eq = m.back();
    m.pop_back();

    vector<vector<long long>> n;
    for (auto &aa: m) {
        vector<long long> c;
        for (string &a: aa) {
            c.push_back(stoll(a));
        }
        n.push_back(c);
    }

    const int rows = n.size();
    const int cols = n[0].size();
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (eq[j] == "*") {
                n[0][j] *= n[i][j];
            } else {
                n[0][j] += n[i][j];
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < cols; i++) {
        res += n[0][i];
    }

    cout << res << endl;
}

