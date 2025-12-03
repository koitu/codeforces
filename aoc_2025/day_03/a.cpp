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

    int result = 0;
    while (getline(file, line)) {
        const int n = line.size();

        int left_mx = line[0];
        int left_idx = 0;
        for (int i = 0; i < n-1; i++) {
            if (line[i] > left_mx) {
                left_mx = line[i];
                left_idx = i;
            }
        }

        int right_mx = line[n-1];
        for (int i = n-1; i > left_idx; i--) {
            if (line[i] > right_mx) {
                right_mx = line[i];
            }
        }

        result += (left_mx - '0') * 10 + (right_mx - '0');
    }

    cout << result << endl;
}

