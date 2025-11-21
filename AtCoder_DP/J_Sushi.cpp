#include <bits/stdc++.h>
using namespace std;

double n;
vector<vector<vector<double>>> dp;

double f(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    if (dp[a][b][c] >= 0) {
        return dp[a][b][c];
    }

    double k = a + b + c;
    dp[a][b][c] = (n/k) 
        + c/k * f(a, b+1, c-1)
        + b/k * f(a+1, b-1, c)
        + a/k * f(a-1, b, c);
    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dp = vector<vector<vector<double>>>(n+1,
            vector<vector<double>>(n+1,
                vector<double>(n+1, -1)));
    dp[0][0][0] = 0;

    int a = 0;
    int b = 0;
    int c = 0;
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v == 1) {
            a++;
        }
        if (v == 2) {
            b++;
        }
        if (v == 3) {
            c++;
        }
    }

    cout << setprecision(16) << f(a, b, c) << endl;
}
