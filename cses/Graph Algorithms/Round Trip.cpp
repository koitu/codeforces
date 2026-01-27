#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // if we disallow backtracking (i.e. a -> b -> a)
    // then any traversal will include another city

    // oof I am pretty bad at graph theory....
    //
    // main idea: use something like topo sort to find a cycle
    // -> if there is a cycle it will be found by topo
    // -> although requires directed graph we will just disallow backtracking (same thing?)
}

