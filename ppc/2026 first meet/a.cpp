#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, char c) {
    vector<string> ss;
    size_t pos = 0;
    string cur;

    while ((pos = s.find(c)) != string::npos) {
        ss.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    ss.push_back(s);

    return ss;
}

void solve() {
    string s;
    cin >> s;

    vector<string> ss = split(s, '+');

    cout << stoi(ss[0]) + stoi(ss[1]) << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
