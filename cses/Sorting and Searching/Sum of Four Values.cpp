#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    // n is up to 1000
    // even 1e9 is too much
    
    // idea: split the array into half, then we have 5 cases:
    // - all values are to the left -> recurse until like 10 elements?
    // - 3 left, 1 right -> ???
    // - 2 left, 2 right -> comparing two sets of 500*500 = 250,000 elements
    // - 1 left, 3 right
    // - all values are to the right
    // 
    // can also sort and compare to prune branchs that are just not possible


}

