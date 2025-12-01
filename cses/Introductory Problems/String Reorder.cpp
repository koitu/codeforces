#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> chars(26, 0);
    int n;
    char c;
    while (cin.get(c) && c != '\n') {
        char[c - 'A']++;
        n++;
    }

    // we want the lowest to be at the front
    // then the next lower to be interweaved until we reach the end
    //
    // AAABBBCCCDDD
    // ABABAB CCCDDD
    // ABABCACBC DDD
    // ABABCACDBDCD
    //
    // ABABABCDCDCD
    // +2 C
    // ABABACBCDCDCDC
    //
    // AAABBBCCCCCCDDD
    // ABABABCCCCCCDDD
    // ABABABCCCDCDCDC (extra flow goes backwards)
    // ABABCACBCDCDCDC
    // if we didn't fully saturate D then it would also flow backwards
    //
    // can we do something like backtracking for this or do we need to smarter?
    //
    // idea:
    // - flow the current letter into the next ones
    // - we can also store a letter between two ones
    // - if the letters are not fully saturated then continue flowing
    // - at the end once our flow goes out the flow goes backwards
    //
    // now how to actually implement this idea...
    // 
    // idea: 
    // - create the minimum string thing
    // - use two pointers
    // - i will point to the "from" and j will point to "to"
    // - i will iterate over while j will point to the first different char
    // - if i detects a dup (with i-1) swap i and j
    // - at the end we deal with the bunch of extra?
}

