#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    // want to find time to visit all length-wise and row-wise
    // check if times gcd is 1?
    //
    // recall a mod n has an inverse iff a and n are coprime (i.e. gcd(a, n) = 1)

    int nn = gcd(n, a);
    int mm = gcd(m, b);
    // if (nn > 1 || mm > 1) {
    //     cout << "NO" << endl;
    // }
    // int nm = gcd(a, b);

    // if nn and mm == 1 then we know that every length-wise and row-wise is visited
    // however how many steps does this take? should just be n and m
    // if gcd of these steps are greater than 1 then we also fail as then there is some cycle in there preventing visiting all

    int nm = gcd(n, m);

    // cout << nn << " " << mm << " " << nm << endl;
    // cout << (max(nm, max(nn, mm)) == 1 ? "YES" : "NO") << endl;
    if (nn > 1 || mm > 1 || nm > 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
