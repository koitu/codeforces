#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // two people reading books
    // we know the time it takes to read each book
    // however we only have a single copy of each book and both people want to read all the books
    //
    // get the minimum time to do this
    //
    // idea: p1 reads the books from longest to shortest then p2 reads the longest book that the other person is not reading
    // - when p1 finishes the longet book they will then work on the second longest book (which p2 must have finished) 
    //
    // idea:
    // - p1 reads from longest to shortest book
    // - p2 reads from 2nd longest to shortest book then longest book
    // - the entire time they are reading p2 will be slightly ahead of p1 

    vector<long long> a(n);
    long long sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    sort(a.begin(), a.end());
    long long mx = a[n-1];
    sm -= mx;

    // case 1:
    // p1: [ mx ] [ sm ]
    // p1: [ sm ] [ mx ] 
    //
    // case 2:
    // p1: [ mx    ] [ sm ]
    // p1: [ sm ]    [ mx    ] 
    //
    // case 3:
    // p1: [ mx ] [ sm    ]
    // p1: [ sm    ] [ mx ] 

    cout << max(mx + sm, mx + mx) << endl;
}

