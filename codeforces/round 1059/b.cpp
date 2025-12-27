#include <bits/stdc++.h>
using namespace std;

set<int> res;
bool checkp(const vector<char> &s) {
//bool checkp(const int a, const int b, const vector<char> &s) {
    int i = 0;
    int j = s.size() - 1;
    while (res.find(i) != res.end()) {
        i++;
    }
    while (res.find(j) != res.end()) {
        j--;
    }
//    if (a <= i && i <= b) {
//        i = b + 1;
//    }
//    if (a <= j && j <= b) {
//        j = a - 1;
//    }

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;

        while (res.find(i) != res.end()) {
            i++;
        }
        while (res.find(j) != res.end()) {
            j--;
        }
//        if (a <= i && i <= b) {
//            i = b + 1;
//        }
//        if (a <= j && j <= b) {
//            j = a - 1;
//        }
    }

    return true;
}

//void solve() {
//    int n;
//    cin >> n;
//    vector<char> s(n);
//    for (int i = 0; i < n; i++) cin >> s[i];
//
//    // three cases:
//    // p is at the start
//    // p is in middle
//    // p is at end
//    // string is only n <= 10 so can just brute force
//
//    // see if trival p works
//    if (checkp(-1, -1, s)) {
//        cout << 0 << endl << endl;
//        return;
//    }
//
//
//    for (int i = 0; i < n; i++) {
//        for (int j = i; j < n; j++) {
//            bool valid = true;
//
//            // check non-decreasing
//            char cur = s[i];
//            for (int k = i+1; k <= j; k++) {
//                if (cur > s[k]) {
//                    valid = false;
//                    break;
//                }
//                cur = max(cur, s[k]);
//            }
//
//            // check palindrome
//            if (valid && !checkp(i, j, s)) {
//                valid = false;
//            }
//
//            if (valid) {
//                cout << (j - i + 1) << endl;
//                for (int k = i; k <= j; k++) {
//                    cout << k+1 << " ";
//                }
//                cout << endl;
//                return;
//            }
//        }
//    }
//
//    cout << -1 << endl;
//}

bool backtrack(vector<char> &s, const int i) {
    if (i == s.size()) {
        if (checkp(s)) {
            cout << res.size() << endl;
            for (int j: res) {
                cout << j + 1 << " ";
            }
            cout << endl;
            return true;
        }

        return false;
    }

    if (backtrack(s, i+1)) {
        return true;
    }

    res.insert(i);

    bool valid = true;
    char cur = '0';
    for (int j: res) {
        if (cur > s[j]) {
            valid = false;
            break;
        }
        cur = max(cur, s[j]);
    }

    if (valid && backtrack(s, i+1)) {
        return true;
    }

    res.erase(i);

    return false;
}

void solve() {
    res.clear();

    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    if (!backtrack(s, 0)) {
        cout << -1 << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
