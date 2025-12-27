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

    vector<pair<long long, long long>> rs;
    while (getline(file, line)) {
        if (line.empty()) {
            break;
        }

        vector<string> r = split(line, "-");
        rs.emplace_back(stoll(r[0]), stoll(r[1]));
    }

    int result = 0;
    while (getline(file, line)) {
        long long i = stoll(line);
        for (auto [l, r]: rs) {
            if (l <= i && i <= r) {
                result++;
                break;
            }
        }
    }


    cout << result << endl;
}

