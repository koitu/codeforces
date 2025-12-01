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
        res += (move / MOD);
        move %= MOD;

        if (line[0] == 'L') {
            if (pos == 0) {
                pos = 100;
            }

            pos -= move;
            if (pos <= 0) {
                res++;
                pos += MOD;
            }

        } else {
            pos += move;
            if (pos >= MOD) {
                res++;
            }
        }

        pos %= MOD;
        // cout << pos << " " << res << endl;
    }

    cout << res << endl;
}

