#include <bits/stdc++.h>
using namespace std;

vector<string> result;
vector<char> cur;

int n;
vector<int> have;
vector<char> chars;

void backtrack() {
    bool allused = true;
    for (int i = 0; i < n; i++) {
        if (have[i] > 0) {
            allused = false;
            break;
        }
    }

    if (allused) {
        result.push_back(string(cur.begin(), cur.end()));
        return;
    }

    for (int i = 0; i < n; i++) {
        if (have[i] > 0) {
            have[i]--;
            cur.push_back(chars[i]);

            backtrack();

            cur.pop_back();
            have[i]++;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> m;
    for (char c: s) {
        m[c]++;
    }
    for (auto [k, v]: m) {
        have.push_back(v);
        chars.push_back(k);
    }
    n = have.size();

    // backtracking
    // first push the larger char then the less large
    backtrack();

    cout << result.size() << endl;
    for (string& r: result) {
        cout << r << endl;
    }
}

