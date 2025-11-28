#include <bits/stdc++.h>
using namespace std;

int n = 8;

int result = 0;
vector<vector<bool>> blocked(n, vector<bool>(n, false));
vector<int> state = vector<int>(n, 0);
// stores the state via a bitmask
// - 1 -> left flying
// - 2 -> center
// - 4 -> right flying
// imagine a queen shooting three lazers downwards after we place it

void backtrack(int level) {
    if (level == n) {
        result++;
        return;
    }

    // the previous state
    vector<int> save(state.begin(), state.end());

    // update the current state
    // - check left and right flying at the corners
    // - update the flying
    if (state[0] & 1) {
        state[0] -= 1;
    }
    if (state[n-1] & 4) {
        state[n-1] -= 4;
    }
    for (int i = 0; i < n; i++) {
        // note the order we perform the updates in
        if (state[i] & 1) {
            state[i-1] += 1;
            state[i] -= 1;
        }
        if (state[n-1-i] & 4) {
            state[n-i] += 4;
            state[n-1-i] -= 4;
        }
    }

    // place a queen whereever we can
    for (int i = 0; i < n; i++) {
        if (!blocked[level][i] && state[i] == 0) {
            state[i] = 1 + 2 + 4; // the next level will update this to fan out
            backtrack(level+1);
            state[i] = 0;
        }
    }

    // restore the previous state
    state = save;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // we need to place 8 queens
    // we know for sure that they can't be on the row so we will try to place a queen on each row

    // 8**8 is about 17 million
    // brute force by using backtracking
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') {
                blocked[i][j] = true;
            }
        }
    }

    backtrack(0);

    cout << result << endl;
}

