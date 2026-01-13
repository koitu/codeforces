#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // sqrt decomp
    // sqrt(n) where n is 1e5 is about 1e3 and 1e8 (100 million) should be feasible in 1 second
    // it appears that this is a little bit too slow... (around 1.5-2 seconds for the largest cases...)
    const int sq = ceil(sqrt(n));
    list<list<int>> vals;
    list<int> hold;
    for (int i = 1; i <= n; i++) {
        hold.push_back(i);

        if (hold.size() >= sq) {
            vals.push_back(hold);
            hold.clear();
        }
    }
    vals.push_back(hold);
    hold.clear();

    // for (auto v: vals) {
    //     for (auto vv: v) {
    //         cout << vv << " ";
    //     }
    //     cout << endl;
    // }

    auto con = vals.begin();
    int tot_left = n;

    auto it = con->begin();
    int cur_left = con->size();

    for (int i = 0; i < n; i++) {
        int kk = k % tot_left;
        // cout << tot_left << " " << kk << endl;
        // for (auto v: vals) {
        //     for (auto vv: v) {
        //         cout << vv << " ";
        //     }
        //     cout << endl;
        // }

        // jump across segments until we get to the correct location
        // at max sqrt(n) jumps
        while (kk >= cur_left) {
            kk -= cur_left;

            // con = next(con);
            con = (con->size() == 0) ? vals.erase(con) : next(con);
            if (con == vals.end()) {
                con = vals.begin();
            }

            it = con->begin();
            cur_left = con->size();
        }

        // move withint the segment (we konw that kk is strictly larger than cur_left so we will not be at the end)
        // while (kk-- > 0) {
        //     it = next(it);
        //     cur_left--;
        // }
        it = next(it, kk);
        cur_left -= kk;

        // // if we are at the end of a segment
        // if (it == con->end()) {
        //     con = next(con);
        //     if (con == vals.end()) {
        //         con = vals.begin();
        //     }

        //     it = con->begin();
        //     cur_left = con->size();
        // }

        // erase the current element
        // cout << *it << endl << endl;
        cout << *it << " ";
        it = con->erase(it);
        cur_left--;
        tot_left--;

        // if (it == con->end()) {
        //     con = (con->size() == 0) ? vals.erase(con) : next(con);
        //     if (con == vals.end()) {
        //         con = vals.begin();
        //     }

        //     it = con->begin();
        //     cur_left = con->size();
        // }
    }

    cout << endl;
}

