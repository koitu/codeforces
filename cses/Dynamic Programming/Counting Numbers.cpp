#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(18, vector<int>(10, 0));


int get_result(const string s) {
    int result = 0;
    const int n = s.length();

    int cur = s[n-1] - '0';
    for (int i = 0; i < cur; i++) {
        result += dp[n-1][i];
    }

    for (int i = n - 2; i >= 0; i--) {
        int prv = cur;
        cur = s[i] - '0';

        for (int j = 0; j <= cur; j++) {
            if (prv != j) {
                result += dp[i][j];
            }
        }
    }

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    // numbers with 1 digit have a count of one
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < 18; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j != k) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }

    cout << get_result("9") << endl;
    cout << get_result("89") << endl;
    cout << get_result("99") << endl;
    cout << get_result("001") << endl;
    cout << get_result("899") << endl;
    cout << get_result("999") << endl;
    cout << get_result("0001") << endl;
    cout << get_result(a) << " " << get_result(b) << endl;
    cout << get_result(a) - get_result(b) << endl;
}

