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
    if (n & 1) {
        return false;
    }

    n /= 2;
    int half = 1;
    for (int i = 0; i < n; i++) {
        half *= 10;
    }

    return (v / half) == (v % half);
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

