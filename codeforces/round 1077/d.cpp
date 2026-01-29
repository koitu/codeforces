#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long x, y;
    cin >> x >> y;

    if ((x & y) == 0) {
        cout << x << " " << y << endl;
        return;
    }

    // for each bit we have 3 options
    // - put it nowhere
    // - put it in p
    // - put it in q

    bitset<40> bx(x);
    bitset<40> by(y);
    bitset<40> common(x & y);
    // we want to turn all the common 1s to 0s while minimizing the diff
    //
    // we saw a solution that is removing all common 1s
    // however notice that we can also add a value to remove it
    // issue: which side to add to

    // // first solution
    // int res = x & y;
    // cout << x << " " << (y ^ res) << endl;

    // idea: for each series of common bits 1s
    // we only lose 1 when we replace it with a 1 the left
    // we lose the series if we replace it with 1s to the right
    //
    // for each series of common 1s
    // - we can remove it
    // - add 1 to it (best if the series of common 1s goes to end of the number)
    vector<tuple<int, int, int>> res;
    res.emplace_back(x & y, x, y - (x & y));

    // idea: is the best solution always possible if we only modify one side?
    // proof by "I can't find a counterexample right now"
    // notice that for each bit we can either push it up one or completely sub it out
    // they both cost the same to do however pushing it up can knock down more (works great only if the other side doesn't have a 1 in that place)
    //
    // idea: find the highest index that has a common 1
    // try the add method on both sides
    int hi = 0;
    for (int i = 0; i < 40; i++) {
        if (common[i]) {
            hi = i;
        }
    }

    // try subtraction
    bx[hi] = false;
    for (int i = 0; i < hi; i++) {
        bx[i] = !by[i];
    }
    int xx = bx.to_ulong();
    res.emplace_back(x - xx, xx, y);
    bx = bitset<40>(x);

    by[hi] = false;
    for (int i = 0; i < hi; i++) {
        by[i] = !bx[i];
    }
    int yy = by.to_ulong();
    res.emplace_back(y - yy, x, yy);
    by = bitset<40>(y);

    // try addition
    // at least one side must have the hi+1 spot with a zero
    if (!bx[hi+1]) {
        for (int i = 0; i <= hi; i++) {
            by[i] = false;
        }
        by[hi+1] = true;

        yy = by.to_ulong();
        res.emplace_back(yy - y, x, yy);
        by = bitset<40>(y);
    }
    if (!by[hi+1]) {
        for (int i = 0; i <= hi; i++) {
            bx[i] = false;
        }
        bx[hi+1] = true;

        xx = bx.to_ulong();
        res.emplace_back(xx - x, xx, y);
        bx = bitset<40>(x);
    }

    sort(res.begin(), res.end());
    auto [_, p, q] = res[0];
    cout << p << " " << q << endl;




    // ideas: split into two cases
    // - when MSB is the same between the x and y
    // - when MSB is greater 
    // shit...

    // back to first principles
    // for each bit we can either put it in p or q or neither
    // brute force is easy but I can't think of a smarter way...

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
