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

    int pos = 50;
    int res = 0;
    const int MOD = 100;

    while (getline(file, line)) {
        int move = stoi(line.substr(1));
        if (line[0] == 'L') {
            move = MOD - move;

        }

        pos = (pos + move) % MOD;
        if (pos == 0) {
            res++;
        }
    }

    cout << res << endl;
}

