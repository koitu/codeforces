#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
int n, m;

// for dp we just need to know current and prev
vector<long long> a;
vector<long long> b;

// always set to zero to start
bitset<10> prv;
bitset<10> cur;

// use backtracking to get all the valid tilings for the first loc
void init(const int i) {
    if (i == n) {
        a[(int)cur.to_ulong()] = 1LL;
        return;
    }
    if (i > n) {
        return;
    }

    // at each pos i we can either choose 1 or two 0s in a row
    cur.set(i, true);
    init(i + 1);
    cur.set(i, false);
    init(i + 2);
}

void dp(const int i) {
    // we arrived at the end so get rid of prv's 1s
    if (i == n) {
        int x = (int)prv.to_ulong();
        int y = (int)(cur ^ prv).to_ulong();
        b[y] = (b[y] + a[x]) % MOD;
        return;
    }

    // no choices to be made if already 1
    if (cur[i] == 1) {
        dp(i+1);
        return;
    }

    // at each pos i we can either choose 1 or two 0s in a row
    // - at the last pos we cannot be zero
    // - if at the next pos the prev we a 1 then we cannot pick zero
    cur.set(i, true);
    dp(i + 1);
    cur.set(i, false);
    if (i != n - 1 && !cur[i+1]) {
        dp(i + 2);
    }
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    // we will treat this as like n rows and use a bitmask to represent the state
    // for every 1 we have a tile pointing to next
    //
    // at every position we look at the previous (only consider non-zero)
    // cur bitmask is valid when (cur & prv) == 0 && valid(cur | prv)
    // 
    // dp[i][mask] 
    // - i the current row
    // - mask are the locations of 1x2 (sticking out to the next column) pieces
    a = vector<long long>(2048, 0LL);
    b = vector<long long>(2048, 0LL);

    init(0); // i = 0

    for (int i = 1; i < m; i++) {

        // for valid current items find the number of ways we can make the current step
        for (int j = 0; j < 2048; j++) {
            if (a[j] == 0) continue;

            prv = bitset<10>(j);
            cur = bitset<10>(j);
            dp(0);
        }

        // if this is too slow them maybe just allocate big chunk of mem in beginnning
        fill(a.begin(), a.end(), 0LL);
        swap(a, b);
    }

    // the last one should be valid and not include any ones (no extending past)
    cout << a[0] << endl;
}

