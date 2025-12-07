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
    vector<long long> cur(n, 0);
    for (int i = 0; i < n; i++) {
        if (line[i] == 'S') {
            cur[i] = 1;
            break;
        }
    }
    getline(file, line);

    vector<long long> nxt;
    while (getline(file, line)) {
        nxt = vector<long long>(n, 0);

        for (int i = 0; i < n; i++) {
            if (line[i] == '^' && cur[i]) {
                nxt[i-1] += cur[i];
                nxt[i+1] += cur[i];

            } else if (cur[i]) {
                nxt[i] += cur[i];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << nxt[i] ? '|' : '.';
        // }
        // cout << endl;
        swap(cur, nxt);
        getline(file, line);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += cur[i];
    }

    cout << res << endl;
}

