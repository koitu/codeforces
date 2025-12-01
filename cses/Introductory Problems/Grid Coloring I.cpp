#include <bits/stdc++.h>
using namespace std;

int pick(int b) {
    for (int i = 0; i < 4; i++) {
        if ((b & (1 << i)) == 0) {
            return 1 << i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // convert chars to bitmask
    // A -> 1
    // B -> 2
    // C -> 4
    // D -> 8
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> res(n, vector<int>(m, 0));
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            grid[i][j] = (1 << (c - 'A'));
        }
    }

    // looked at solution
    // somehow greedy works here, something about how each choice only affects the local adjacent
    // this doesn't seem right but it appears to work so ...

    // for the first row we can't pick left and current
    // for later rows we can't pick left current and up
    // when is this ever impossible? it seems there are always at most 3 choices blocked off...
    
    // get top left
    res[0][0] = pick(grid[0][0]);

    // then iterate over first row and first col
    for (int i = 1; i < m; i++) {
        res[0][i] = pick(grid[0][i] | res[0][i-1]);
    }
    for (int i = 1; i < n; i++) {
        res[i][0] = pick(grid[i][0] | res[i-1][0]);
    }


    // then iterate over the rest
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            res[i][j] = pick(grid[i][j] | res[i][j-1] | res[i-1][j]);
        }
    }

    map<int, char> conv;
    for (int i = 0; i < 4; i++) {
        conv[1 << i] = 'A' + i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << conv[res[i][j]];
        }
        cout << endl;
    }
}

