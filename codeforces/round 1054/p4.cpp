#include <bits/stdc++.h>
using namespace std;


long long get_min_moves(const vector<bool> &v, const bool block) {
    // soln: target is to make all occurances of one letter contiguous
    //  to do this we want to minimize the amount of moves to make it all contiguous
    //  find a position L where the minimum number of swaps are needed
    //
    //  since we are trying to minimize sum |p - L| we take L to be the median
    //  the derivative of |x| is sign(x) and if L is the median then sign(x - L) = 0
    vector<int> pos;

    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == block) {
            // bi = pi - i
            pos.push_back(i - j);
            j++;
        }
    }

    int median;
    if (j % 2 == 1) {
        median = pos[j / 2];
    } else {
        median = round(double(pos[(j / 2) - 1] + pos[j / 2]) / 2.0);
    }

    long long res = 0;
    for (int i = 0; i < j; i++) {
        res += (long long)abs(pos[i] - median);
    }

    return res;

//    const int n = v.size();
//
//    // count is number of side we need to move to the side
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        if (v[i] == side) {
//            count++;
//        }
//    }
//
//    // check the number already at the side
//    int i, j;
//    for (i = 0; i < n; i++) {
//        if (v[i] != side) {
//            break;
//        }
//        count--;
//    }
//    for (j = n - 1; j >= 0; j--) {
//        if (v[j] != side) {
//            break;
//        }
//        count--;
//    }
//
//    // the number of moves to move side to the side 
//    int moves = 0;
//    int left = 1;
//    int right = 1;
//    while (count > 0) {
//        // choose the side we are closer to
//        if (left <= right) {
//            i++;
//
//            if (v[i] != side) {
//                left++;
//            } else {
//                count--;
//                moves += left;
//            }
//
//        } else {
//            j--;
//
//            if (v[j] != side) {
//                right++;
//            } else {
//                count--;
//                moves += right;
//            }
//        }
//    }
//
//    return moves;
}

void solve() {
    int n;
    cin >> n;
    // Your code here
    // when reading left to right we should switch at most 2 times
    // each time we swap we move one character closer to another
    // idea: choose one of a or b, determine the number of the other character is between them

    // it would probably make sense to use a bitset to make this more mem efficient?
    vector<bool> v(n, false);
    int count = 0;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'a') {
            v[i] = true;
            count++;
        }
    }

    if (count == 0 || count == n) {
        cout << 0 << endl;
        return;
    }

    cout << min(get_min_moves(v, false), get_min_moves(v, true)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
