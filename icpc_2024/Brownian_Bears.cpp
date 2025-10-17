#include <bits/stdc++.h>
using namespace std;


void solve() {
    // 2 <= n <= 100 -> number of locations
    // x and y are the two bear locations
    // d is the number of observation days
    int n, x, y, d;
    cin >> n >> x >> y >> d;

    // f(d,x,y) = 1/4 (f(d-1, x-1, y-1) + f(d-1,x+1,y-1) + f(d-1,x-x-1,y+1), f(d-1,x+1,y+1))
    // we want the probability that the bears will never meet during the d days
    // thus whenever the bears meet we don't count it
    //  (this is why we can't use the method where we track where the bears are and the prob they meet?)

    vector<__int128> xn(n, 0);
    vector<__int128> xd(n, 0);
    vector<__int128> yn(n, 0);
    vector<__int128> yd(n, 0);

    xn[x-1] = 1;
    xd[x-1] = 1;
    yn[x-1] = 1;
    yd[x-1] = 1;

    for (int i = 0; i < d; i++) {

    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
