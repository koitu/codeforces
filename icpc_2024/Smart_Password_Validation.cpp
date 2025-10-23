#include <bits/stdc++.h>
using namespace std;

// map<char, char> leftShift;
// map<char, char> rightShift;

constexpr vector<string> left = vector<string>{
    "`1234567",
    "~!@#$%^&",
    "qwerty",
    "QWERTY",
    "asdfgh",
    "ASDFGH",
    "zxcvbn",
    "ZXCVBN",
};

constexpr vector<string> right = vector<string>{
    "67890-=",
    "^&*()_+",
    "tyuiop[]\\",
    "TYUIOP{}|",
    "ghjkl;\'",
    "GHJKL:\"",
    "vbnm,./",
    "VBNM<>?",
};

bool eq_one_off(string a, string b) {
    if (a.length() < b.length()) {
        swap(a, b);
    }

    const int n = b.length();
    int i = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] 
    }
}


void solve(const string pw) {
    string ty;
    cin >> ty;

    if (abs(ty.length() - pw.length()) > 1) {
        cout << "NO" << endl;
    }

    if (ty.length() == pw.length()) {
        // check LS (left shift)

        // check RS (rigth shift)
        
        // check CL (caps lock)

    } else {
        // we know that the difference between string lengths is one character
        if (pw.length() > ty.length()) {
            // check MC (single missing character)

        } else {
            // check EC (single extra character)

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string password;
    cin >> password;

    int t;
    cin >> t;

//    leftShift['`'] = '1';
//    leftShift['1'] = '2';
//    leftShift['2'] = '3';
//    leftShift['3'] = '4';
//    leftShift['4'] = '5';
//    leftShift['5'] = '6';
//    leftShift['6'] = '7';
//
//    leftShift['~'] = '!';
//    leftShift['!'] = '@';
//    leftShift['@'] = '#';
//    leftShift['#'] = '$';
//    leftShift['$'] = '%';
//    leftShift['%'] = '^';
//    leftShift['^'] = '&';
//
//    leftShift['q'] = 'w';
//    leftShift['a'] = 's';
//    leftShift['z'] = 'x';
//    leftShift['w'] = 'e';
//    leftShift['s'] = 'd';
//    leftShift['x'] = 'c';
//    leftShift['e'] = 'r';
//    leftShift['d'] = 'f';
//    leftShift['c'] = 'v';
//    leftShift['r'] = 't';
//    leftShift['f'] = 'g';
//    leftShift['v'] = 'b';
//    leftShift['t'] = 'y';
//    leftShift['g'] = 'h';
//    leftShift['b'] = 'n';
//    // remember to_lower and to_upper since we are only mapping lowercase
//    
//    rightShift['='] = '-';
//    rightShift['-'] = '0';
//    rightShift['0'] = '9';
//    rightShift['9'] = '8';
//    rightShift['8'] = '7';
//    rightShift['7'] = '6';
//
//    rightShift['+'] = '_';
//    rightShift['_'] = ')';
//    rightShift[')'] = '(';
//    rightShift['('] = '*';
//    rightShift['*'] = '&';
//    rightShift['&'] = '^';
//
//    rightShift['\\'] = ']';
//    rightShift[']'] = '[';
//    rightShift['['] = 'p';
//    rightShift['|'] = '}';
//    rightShift['}'] = '{';
//    rightShift['{'] = 'P';

    while (t--) solve(password);
}
