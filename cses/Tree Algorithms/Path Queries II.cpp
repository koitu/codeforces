#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // two operations:
    // 1. change the value of node s to x
    // 2. find the maximum value of the path between nodes a and b

    // observations:
    // - since we care about the path between a and b we probably need segtree for LCA
    // - max operation doesn't have an inverse so can't use same trick as Path Queries

    // thinking:
    // - lets try to reduce the difficulty and consider when a is the root so LCA(a, b) = a
    // - how can the segtree store values so that when we query we can max of the path from root to b
    //  - similar idea to before:
    //      - store some repr of the max value in first[b]
    //      - store some repr of the inverse of the max value in last[b]
    //      - doesn't really work
    // - think more base level: how can we use the fact that we can quickly find the max in a range
    //  - what about having more than one segtree so when we do range query we don't get extra crap
    //  - split up the problem into before the lca and after the lca
    //  - 

    //     1
    //   2   3
    //  4 5

    //     2
    //   4   1
    //  3 3

    // tour start and ends: 1 2 4 4 5 5 2 3 3 1
    // tour all: 1 2 4 2 5 2 1 3 1
    // tour all: 1 2 4 4 2 5 5 2 1 3 3 1
    //                           ^
    //                       |-----|
    //                        5->3
    //                 |-----------|
    //                  4->3 (passes through 5)
    // 
    // - consider: what if we can find the sum of all the numbers in the range excluding the max
    //  - rolling max problem? what size? if we need every size that is like n(n+1)/2 or n^2
    //  - somehow need to exclude entries that appear twice from the max calculation
    //      - have some weird method of merging?
    //      - precalculate the elements for every step of merging (can be reused for update)
    // - binary lifing has very slow update :(

    // skipped for now
}

