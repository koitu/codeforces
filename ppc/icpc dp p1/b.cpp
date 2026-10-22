#include <bits/stdc++.h>
using namespace std;

long long dp[60][60][60][4];

void solve() {
    int n, k;
    cin >> n >> k;

    fill(&dp[0][0][0][0], &dp[0][0][0][0] + (60 * 60 * 60 * 4), 0);
    
    // - three panels: A, B, C
    // - create a sequence of characters following the rules:
    //   - variety:
    //      - panel A and C cannot be lit for two weeks in a row
    //      - panel B cannot be lit for three weeks in a row
    //   - balance:
    //      - if we light up each panel a b c times
    //      - for some d
    //      - we cannot have |a - b| > d or |b - c| > d or |c - a| > d
    //   - aibohphobia:
    //      - no spotlight sequence can be a palindrome (same forward or backward)
    //      - no sub?

    // bitmask dp?
    // - what do we store in the previous state?
    // - bitmask to store the previous light
    // - 3D to store the balance
    // - look at it halfway to find the number of palindromes


    // problem: ordering
    // - all the ways to get sequences of length n
    // - all the ways to get seuqences of length n + 1
    //
    // - we only care about balance when we get to the end
    // - we can do panlindromes later

    // if the bitmask is just 0 then allow any
    // (don't need bitmask since states are non-overlapping)
    const int a1 = 0;
    const int b1 = 1;
    const int b2 = 2;
    const int c1 = 3;
    dp[1][0][0][a1] = 1;
    dp[0][1][0][b1] = 1;
    dp[0][0][1][c1] = 1;

    // length of sequence
    for (int i = 2; i <= n; i++) {

        // all the ways to make a sequence of length i
        for (int a = 0; a <= i; a++) {
            for (int b = 0; b <= i - a; b++) {
                int c = i - a - b;

                // A
                if (a > 0) {
                    dp[a][b][c][a1] = dp[a-1][b][c][b1] + dp[a-1][b][c][b2] + dp[a-1][b][c][c1];
                }

                // B
                if (b > 0) {
                    dp[a][b][c][b1] = dp[a][b-1][c][a1] + dp[a][b-1][c][c1];
                    dp[a][b][c][b2] = dp[a][b-1][c][b1];
                }

                // C
                if (c > 0) {
                    dp[a][b][c][c1] = dp[a][b][c-1][a1] + dp[a][b][c-1][b1] + dp[a][b][c-1][b2];
                }
            }
        }
    }

    // deal with balance
    long long res = 0;
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= n - a; b++) {
            int c = n - a - b;
            if (abs(a - b) > k || abs(b - c) > k || abs(c - a) > k) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                res += dp[a][b][c][i];
            }
        }
    }

    // deal with palendromes
    const int n2 = n / 2;
    if (n & 1) {
        // odd len: reduce by number of ways we can get center that is different from others while also maintaining balance
        for (int a = 0; a <= n2; a++) {
            for (int b = 0; b <= n2 - a; b++) {
                int c = n2 - a - b;

                int aa = a * 2;
                int bb = b * 2;
                int cc = c * 2;

                // pick a as the center
                if (abs(aa + 1 - bb) <= k && abs(bb - cc) <= k && abs(aa + 1 - cc) <= k) {
                    res -= dp[a][b][c][b1] + dp[a][b][c][b2] + dp[a][b][c][c1];
                }

                // pick b as center
                if (abs(bb + 1 - aa) <= k && abs(bb + 1 - cc) <= k && abs(cc - aa) <= k) {
                    res -= dp[a][b][c][a1] + dp[a][b][c][c1];
                }

                // pick c as center
                if (abs(aa - bb) <= k && abs(cc + 1 - bb) <= k && abs(cc + 1 - aa) <= k) {
                    res -= dp[a][b][c][a1] + dp[a][b][c][b1] + dp[a][b][c][b2];
                }
            }
        }
        
    } else {
        // even len
        for (int a = 0; a <= n2; a++) {
            for (int b = 0; b <= n2 - a; b++) {
                int c = n2 - a - b;

                int aa = a * 2;
                int bb = b * 2;
                int cc = c * 2;

                // must pick b1 as center
                if (abs(aa - bb) <= k && abs(bb - cc) <= k && abs(aa - cc) <= k) {
                    res -= dp[a][b][c][b1];
                }
            }
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
