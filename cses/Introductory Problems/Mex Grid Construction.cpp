#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // use n vectors to store the used numbers for each column
    // note: the maximum value we can get is if n elements of col and row are all different values
    //
    // at each row keep a set(?) of used numbers

    vector<vector<bool>> used(n, vector<bool>(n*2, false));
    vector<vector<int>> res(n, vector<int>(n));

    // init the first row
    for (int i = 0; i < n; i++) {
        res[0][i] = i;
        used[i][i] = true;
    }

    // get the next rows
    for (int r = 1; r < n; r++) {

        // iterate over the columns in the row
        set<int> row;
        for (int c = 0; c < n; c++) {

            // get the mex (min excluded value)
            for (int v = 0; v < 2*n; v++) {
                if (!used[c][v] && !row.count(v)) {
                    used[c][v] = true;
                    row.insert(v);
                    res[r][c] = v;
                    break;
                }
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << res[r][c] << " ";
        }
        cout << endl;
    }
}

