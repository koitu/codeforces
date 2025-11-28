#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // the Gray code is the list of all 2^n bit strings of length n
    // where each two successive stirng diff by a hamming dist of 1

    // note: 2^16 <= 7000
    
    // gray code for n=2
    // 00 0
    // 01 1
    // 11 3
    // 10 2

    // gray code for n=3
    // 000 0
    // 001 1
    // 011 3
    // 010 2
    // 110 6
    // 100 4
    // 101 5
    // 111 7

    // backtracking?
    // up to 7000 states
    // up to 16 transitions per state

    // idea: copy and flip each time
    // 0 00
    // 0 01
    // 0 11
    // 0 10
    // 1 10
    // 1 11
    // 1 01
    // 1 00
    
    vector<string> cur{"0", "1"};
    vector<string> nxt;

    for (int i = 1; i < n; i++) {
        for (string s: cur) {
            nxt.push_back("0" + s);
        }

        reverse(cur.begin(), cur.end());

        for (string s: cur) {
            nxt.push_back("1" + s);
        }
        swap(cur, nxt);
        nxt.clear();
    }


    for (string s: cur) {
        cout << s << endl;
    }
}

