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

// count the number of paths to out
// 0 -> none
// 1 -> fft
// 2 -> dac
// 3 -> fft and dac
map<string, vector<long long>> r;

vector<long long> backtrack(const string &pos) {
    vector<long long> res(4, 0);

    // if we are at out then mark none as 1
    if (pos == "out") {
        res[0] = 1;
        return res;
    }

    // if we already visited then use it
    if (r.count(pos)) {
        return r[pos];
    }

    // otherwise visit the rest
    for (const string &nxt: m[pos]) {
        vector<long long> cur = backtrack(nxt);
        for (int i = 0; i < 4; i++) {
            res[i] += cur[i];
        }
    }

    // check if current is one of fft or dac
    if (pos == "fft") {
        res[3] += res[2];
        res[1] += res[0];
        res[2] = 0;
        res[0] = 0;
    }
    if (pos == "dac") {
        res[3] += res[1];
        res[2] += res[0];
        res[1] = 0;
        res[0] = 0;
    }

    r[pos] = res;
    return res;
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

    string start = "svr";
    cout << backtrack(start)[3] << endl;
}

