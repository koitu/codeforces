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


bool check(const long long v) {
    int n = to_string(v).size();

    int part = 1;
    for (int i = 1; i < n; i++) {
        part *= 10;

        if (n % i == 0) {
            long long cur = v;
            long long check = cur % part;
            bool valid = true;

            while (cur > 0) {
                if ((cur % part) != check) {
                    valid = false;
                    break;
                }

                cur /= part;
            }

            if (valid) {
                return true;
            }
        }
    }

    return false;
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    long long res = 0;
    while (getline(file, line)) {
        vector<string> ranges = split(line, ",");

        for (const string &range: ranges) {
            if (range == "") {
                continue;
            }
            vector<string> srange = split(range, "-");

            long long start = stoll(srange[0]);
            long long end = stoll(srange[1]);
            for (long long i = start; i <= end; i++) {
                if (check(i)) {
                    res += i;
                }
            }
        }
    }

    cout << res << endl;
}

