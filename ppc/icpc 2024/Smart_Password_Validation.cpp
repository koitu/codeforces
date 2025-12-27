#include <bits/stdc++.h>
using namespace std;

// map<char, char> leftShift;
// map<char, char> rightShift;

constexpr vector<string> left = vector<string>{
    "`123456",
    "~!@#$%^",
    "qwert",
    "QWERT",
    "asdfg",
    "ASDFG",
    "zxcvb",
    "ZXCVB",
};

constexpr vector<string> leftShift = vector<string>{
    "1234567",
    "!@#$%^&",
    "werty",
    "WERTY",
    "sdfgh",
    "SDFGH",
    "xcvbn",
    "XCVBN",
};

constexpr vector<string> right = vector<string>{
    "7890-=",
    "&*()_+",
    "yuiop[]\\",
    "YUIOP{}|",
    "hjkl;\'",
    "HJKL:\"",
    "bnm,./",
    "BNM<>?",
};

constexpr vector<string> rightShift = vector<string>{
    "67890-",
    "^&*()_",
    "tyuiop[]",
    "TYUIOP{}",
    "ghjkl;",
    "GHJKL:",
    "vbnm,.",
    "VBNM<>",
};

bool eq_one_off(string a, string b) {
    if (a.length() < b.length()) {
        swap(a, b);
    }

    // a is one larger than b
    const int n = b.length();

    int i = 0;
    for (; i < n; i++) {
        if (a[i] != b[i]) {
            break;
        }
    }

    for (; i < n; i++) {
        if (a[i+1] != b[i]) {
            return false;
        }
    }

    return true;
}


void solve(const string pw) {
    string ty;
    cin >> ty;

    if (abs(ty.length() - pw.length()) > 1) {
        cout << "NO" << endl;
    }

    if (pw == ty) {
        cout << "YES" << endl;
    }

    if (ty.length() == pw.length()) {
        // check LS (left shift)
        string ls = "";
        const int n = ty.length();

        for (int i = 0; i < n; i++) {
            bool found = false;
            size_t pos;
            for (int j = 0; j < left.size(); j++) {
                if ((pos = left[j].find(ty[i])) != std::string::npos) {
                    ls += leftShift[j][pos];
                    found = true;
                    break;
                }
            }

            if (!found) {
                ls += ty[i];
            }
        }

        // check RS (rigth shift)
        string rs = "";
        for (int i = 0; i < n; i++) {
            bool found = false;
            size_t pos;
            for (int j = 0; j < right.size(); j++) {
                if ((pos = right[j].find(ty[i])) != std::string::npos) {
                    rs += rightShift[j][pos];
                    found = true;
                    break;
                }
            }

            if (!found) {
                rs += ty[i];
            }
        }
        
        // check CL (caps lock)
        string cl = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(ty[i])) {
                if (islower(ty[i])) {
                    cl += toupper(ty[i]);
                } else {
                    cl += tolower(ty[i]);
                }
            }
        }

        if ((pw == ls) || (pw == rs) || (pw == cl)) {
            cout << "YES" << endl;
        }

    } else {
        // we know that the difference between string lengths is one character
        if (eq_one_off(ty, pw)) {
            cout << "YES" << endl;
        }

//        if (pw.length() > ty.length()) {
//            // check MC (single missing character)
//
//        } else {
//            // check EC (single extra character)
//
//        }
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
