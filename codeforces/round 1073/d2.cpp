#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    // s is not necessarily valid
    // n <= 100
    // find the sum of scores of all subsequences t of s
    // - score is 0 when t is not valid bracket seq
    // - score is the max len subsequence r of t that is better than t
    // - otherwise 0

    // goal: find the lengths of all subsequences t of s where
    // - t is valid
    // - there exists some )( with a ( after it

    // notes:
    // - for t to be valid the length must be even
    // - length must be greater or equal to 4

    // counting:
    // - go from left to right picking each ) to be the first )
    // - keep track of the number of ( to the left of the current idx (use as buffer)
    // - to the right, consider ways to pick two or more ( such that we are still valid

    string line;
    cin >> line;

    // find the location of the first opening bracket
    int i = 0;
    for (; i < n; i++) {
        if (line[i] == '(') {
            break;
        }
    }

    // the first opening will be exclusively for the first closing bracket
    // the rest of the opening brackets to the left of the current first closing will be used as buffer to ensure no prefix falls below zero
    i++;
    int left_o = 0;
    for (; i < n; i++) {
        if (line[i] == '(') {
            left_o++;
            continue;
        }

        // using i as the first closing bracket
        // starting from the right notice that the choosing the number of closing brackets determines the length
        //
        // idea: pick a ( to be the leftmost opening bracket
        // - make sure there is another ( to its right
        // - consider the max number of ( we can take by matching with )
        // - for extra ) we can match them with our left_o buffer

        int right_c = 0; // used to match left_o
        for (int j = i + 1; j < n; j++) {
            if (line[j] == ')') {
                right_c++;
                continue;
            }
            

            // brain ded, cannot any more

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
