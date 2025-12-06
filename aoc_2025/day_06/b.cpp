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

    vector<string> all;
    while (getline(file, line)) {
        all.push_back(line);
    }

    vector<string> eq = splitws(all.back());
    all.pop_back();
    const int n = all.back().size();
    const int m = all.size();

    vector<vector<long long>> vals;
    vector<long long> cur;
    for (int i = 0; i < n; i++) {
        bool empty = true;
        long long c = 0;

        for (int j = 0; j < m; j++) {
            if (isdigit(all[j][i])) {
                empty = false;
                c *= 10L;
                c += (long long)(all[j][i] - '0');
            }
        }

        if (empty) {
            vals.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    vals.push_back(cur);

    long long result = 0;
    for (int i = 0; i < eq.size(); i++) {
        long long c = vals[i][0];

        for (int j = 1; j < vals[i].size(); j++) {
            if (eq[i] == "*") {
                c *= vals[i][j];
            } else {
                c += vals[i][j];
            }
        }
        result += c;
    }

    cout << result << endl;
}

