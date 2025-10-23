#include <bits/stdc++.h>
using namespace std;

map<char, char> leftShift;
map<char, char> rightShift;

void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> m(r, vector<char>(c));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    leftShift['`'] = '1';
    leftShift['1'] = '2';
    leftShift['2'] = '3';
    leftShift['3'] = '4';
    leftShift['4'] = '5';
    leftShift['5'] = '6';
    leftShift['6'] = '7';
    leftShift['~'] = '!';
    leftShift['!'] = '@';
    leftShift['@'] = '#';
    leftShift['#'] = '$';
    leftShift['$'] = '%';
    leftShift['%'] = '^';
    leftShift['^'] = '&';
    leftShift['q'] = 'w';
    leftShift['a'] = 's';
    leftShift['z'] = 'x';
    leftShift['w'] = 'e';
    leftShift['s'] = 'd';
    leftShift['x'] = 'c';
    leftShift['e'] = 'r';
    leftShift['d'] = 'f';
    leftShift['c'] = 'v';
    leftShift['r'] = 't';
    leftShift['f'] = 'g';
    leftShift['v'] = 'b';
    leftShift['t'] = 'y';
    leftShift['g'] = 'h';
    leftShift['b'] = 'n';
    // remember to_lower and to_upper since we are only mapping lowercase
    



    solve();
}
