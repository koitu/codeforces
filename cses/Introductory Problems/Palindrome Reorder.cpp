#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char c;
    vector<int> freq(26, 0);
    
    // remark: cin.get does not skip whitespace while >> will
    while (cin.get(c) && c != '\n') {
        freq[c - 'A']++;
    }

    int odd_idx = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] & 1) {
            if (odd_idx == -1) {
                odd_idx = i;
            } else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }

    string mid = "";
    if (odd_idx != -1) {
        mid += 'A' + odd_idx;
        freq[odd_idx]--;
    }

    vector<char> s;
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            s.push_back('A' + i);
            freq[i] -= 2;
        }
    }

    string side(s.begin(), s.end());
    cout << side << mid;

    reverse(side.begin(), side.end());
    cout << side << endl;
}

