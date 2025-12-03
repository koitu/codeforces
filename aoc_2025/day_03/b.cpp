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

    long long result = 0;
    while (getline(file, line)) {
        const int n = line.size();
        vector<char> cur;

        int idx = -1;
        int mx;

        for (int i = 11; i >= 0; i--) {
            idx += 1;
            mx = line[idx];

            for (int j = idx; j < n-i; j++) {
                if (line[j] > mx) {
                    mx = line[j];
                    idx = j;
                }
            }
            cur.push_back(mx);
        }

        // cout << string(cur.begin(), cur.end()) << endl;
        result += stoll(string(cur.begin(), cur.end()));
    }

    cout << result << endl;
}

