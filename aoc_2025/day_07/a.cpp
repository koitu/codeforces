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

    getline(file, line);
    const int n = line.size();
    vector<bool> cur(n, false);
    for (int i = 0; i < n; i++) {
        if (line[i] == 'S') {
            cur[i] = true;
            break;
        }
    }
    getline(file, line);

    int res = 0;
    vector<bool> nxt;
    while (getline(file, line)) {
        nxt = vector<bool>(n, false);

        for (int i = 0; i < n; i++) {
            if (line[i] == '^' && cur[i]) {
                res++;
                nxt[i-1] = true;
                nxt[i+1] = true;

            } else if (cur[i]) {
                nxt[i] = true;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << nxt[i] ? '|' : '.';
        // }
        // cout << endl;
        swap(cur, nxt);
        getline(file, line);
    }

    cout << res << endl;
}

