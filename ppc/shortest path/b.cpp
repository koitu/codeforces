#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    // dp idea: for each node consider the fastest route from it to the end
    // however what if we find a faster bike
    //
    // from the fastest bike consider how long it would take to get towards the end
    // how long would it take to get to the fastest bike
    //
    // from each bike consider how long it would be to get anywhere
    // iterate from the fastest bike to the slowest one
    // be careful of direction
    //
    //
    // from the fastest to the slowest bikes consider how long it takes to get to the end
    // if we got to a city with a faster bike we can skip to the end
    //
    //
    // correct idea: store the distance and which bike as the state you have at each node


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
