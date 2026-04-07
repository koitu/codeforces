#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // k is always 1
    int v;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v;
        a[i] = v;
    }

    vector<bool> p(k, false);
    for (int i = 0; i < k; i++) {
        cin >> v;
        p[v - 1] = true;
    }

    // want to make all values in a equal to x
    bool x = a[v - 1];


    // main idea:
    // - find the left and right stuff
    // - find fix the stuff between the p's
    int cl = 0;
    int cr = 0;

    int cur = x;
    for (int i = 0; i < n; i++) {
        if (cur != a[i]) {
            // when diff then add
            cur = a[i];
            if (cur != x) {
                cl++;
            }
        }

        if (p[i]) break;
    }

    cur = x;
    for (int i = n-1; i >= 0; i--) {
        if (cur != a[i]) {
            // when diff then add
            cur = a[i];
            if (cur != x) {
                cr++;
            }
        }

        if (p[i]) break;
    }

    int i = 0;
    for (; i < n; i++) {
        if (p[i]) break;
    }

    cur = x;
    int swaps = 0;
    vector<int> vals;
    for (; i < n; i++) {
        if (p[i] && swaps > 0) {
            vals.push_back(swaps);
            swaps = 0;
            cur = a[i];
        }
        if (cur == a[i]) continue;

        // when diff then add
        cur = a[i];
        if (cur != x) {
            swaps++;
        }
    }



    
    //cout << cl << " ";
    //for (int v: vals) {
    //    cout << v << " ";
    //}
    //cout << cr << endl;




    // make them all 1 then flip all at once
    int res = 0;
    for (int i = 0; i < vals.size(); i++) {
        while (vals[i] > 1) {
            res += 2;

            if (cr > 0 || cl > 0) {
                if (cr > cl) {
                    cr--;
                } else {
                    cl--;
                }
            }

            vals[i]--;
        }
    }

    if (vals.size() > 1) {
        res += vals.size();

        // spend 1 extra flip to help the sides
        if (cr > 0) {
            res++;
            cr--;
        }
        if (cl > 0) {
            res++;
            cl--;
        }

    } else if (vals.size() == 1) {
        res += 2;

        // spend 1 extra to help both sides
        if (cr > 0 && cl > 0) {
            res++;
        }
        if (cr > 0) {
            cr--;
        }
        if (cl > 0) {
            cl--;
        }
    }

    res += (max(cl, cr) * 2);
    



    //cout << cl << " ";
    //for (int v: vals) {
    //    cout << v << " ";
    //}
    //cout << cr << endl;




    cout << res << endl;

    // I'm sure there is a smarter way maybe by first doing the big long flip then fixing the stuff between and at the ends
    // but I am out of time...
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
