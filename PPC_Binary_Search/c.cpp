#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, k;
    cin >> n >> k;
    // n is too large to be an array
    // 1 billion bytes -> 1GB
    
    // function is like a valley
    long long i = 1;
    long long j = n;
    
    auto sum_to = [&k](const long long m) -> long long {
        return k * m + (m * (m - 1LL))/2LL;
    };
    long long best = sum_to(n);

    while (i <= j) {
        long long m = (i + j) / 2;

        // sum(a1 to ai) - sum(a{i+1} to an)
        // = 2*sum(a1 to ai) - sum(a1 to an)
        long long mid = abs(2LL*sum_to(m) - sum_to(n));
        long long midr = abs(2LL*sum_to(m+1) - sum_to(n));

        if (mid <= midr) {
            best = min(best, mid);
            j = m - 1;
        } else {
            best = min(best, midr);
            i = m + 1;
        }
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
