#include <bits/stdc++.h>
using namespace std;

int result = 0;
vector<int> dirs;

// a little faster
// map<char, pair<int, int>> d;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, 1, -1};

// don't need this
// vector<char> cur;

// a little faster
// vector<vector<bool>> visited(9, vector<bool>(9, false));
bool visited[9][9];

void backtrack(int i, int j, int l) {
    // check if we are a valid path
    //   n
    // w   e
    //   s
    // at our current position if n and s are use then we must go w or e however
    // due to how we got here in the first place once we go one one way
    // we can never reach other other way (same argument for w and e)
    if ((visited[i-1][j] && visited[i+1][j] && !visited[i][j-1] && !visited[i][j+1]) ||
        (visited[i][j-1] && visited[i][j+1] && !visited[i-1][j] && !visited[i+1][j])) {
        return;
    }

    // check if we are at the end
    if (i == 7 && j == 1) {
        if (l == 48) {
            result++;
        }
        return;
    }

    if (l == 48) {
        return;
    }

    visited[i][j] = true;

    if (dirs[l] == 4) {
        // we can go any direction
        for (int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if (!visited[ii][jj]) {
                backtrack(ii, jj, l+1);
            }
        }
    } else {
        // we must go this direction
        int k = dirs[l];
        int ii = i + di[k];
        int jj = j + dj[k];
        if (!visited[ii][jj]) {
            backtrack(ii, jj, l+1);
        }
    }

    visited[i][j] = false;
}


// too slow...
// string s;
// vector<char> cur;
// vector<vector<bool>> visited(7, vector<bool>(7, false));
// 
// // this solution works!
// // just takes like 5 mins
// // one idea could be just to recompute for all ???...??? then match strings
// void backtrack(int i, int j, int l) {
//     if (i < 0 || i > 6 || j < 0 || j > 6 || visited[i][j]) {
//         return;
//     }
//     visited[i][j] = true;
// 
//     // when we have got all the letters
//     if (l == 48) {
//         if (i == 6 && j == 0) {
//             result++;
//             // cout << result << endl;
//         }
//         visited[i][j] = false;
//         return;
//     }
// 
//     // if we reach bottom left before getting all the letters
//     if (i == 6 && j == 0) {
//         visited[i][j] = false;
//         return;
//     }
// 
//     if (s[l] == '?') {
//         // if the current letter is any
//         for (auto [c, dir]: d) {
//             auto [dx, dy] = dir;
// 
//             cur.push_back(c);
//             backtrack(i + dx, j + dy, l+1);
//             cur.pop_back();
//         }
// 
//     } else {
//         // if the current letter is set
//         auto [dx, dy] = d[s[l]];
// 
//         cur.push_back(s[l]);
//         backtrack(i + dx, j + dy, l+1);
//         cur.pop_back();
//     }
// 
//     visited[i][j] = false;
// }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < 9; i++) {
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][0] = true;
        visited[i][8] = true;
    }

    // d['U'] = make_pair(-1, 0);
    // d['D'] = make_pair(1, 0);
    // d['R'] = make_pair(0, 1);
    // d['L'] = make_pair(0, -1);

    string s;
    cin >> s;
    for (char c: s) {
        if (c == '?') {
            dirs.push_back(4);
        } else if (c == 'U') {
            dirs.push_back(0);
        } else if (c == 'D') {
            dirs.push_back(1);
        } else if (c == 'R') {
            dirs.push_back(2);
        } else if (c == 'L') {
            dirs.push_back(3);
        }
    }
    backtrack(1, 1, 0);

    cout << result << endl;
}

