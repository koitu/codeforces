#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // look for the 1
    // something about modular arthimetic

    // consider how many rotations the last one needs
    // carry that backwards and compare how many rotations second last one needs
    // modular
    
    vector<vector<int>> arrs;
    vector<int> cur{a[0]};
    bool startone = (a[0] == 1);
    for (int i = 1; i < n; i++) {
        if ((startone && a[i] != cur.back() + 1) ||
            (!startone && a[i] == cur[0] - 1)) {

            if (!startone) {
                cur.push_back(a[i]);
                i++;
                if (i >= n) {
                    break;
                }
            }

            arrs.push_back(cur);
            cur.clear();
            cur.push_back(a[i]);
            startone = (a[i] == 1);

        } else {
            cur.push_back(a[i]);
        }
    }
    arrs.push_back(cur);

//    vector<int> r;
//    vector<int> m;
//    for (vector<int>& arr: arrs) {
//        m.push_back(arr.size());
//        for (int i = 0; i < arr.size(); i++) {
//            if (arr[i] == 1) {
//                r.push_back(i);
//            }
//        }
//    }

    vector<int> s(arrs.size());
    int rot = 0;
    for (int i = arrs.size() - 1; i >= 0; i--) {
        int tar = arrs[i][0] - 1; // target number of rotations
        int cur = rot % arrs[i].size(); // current number for rotations

        if (tar >= cur) {
            // number of rotations to get to tar
            rot += tar - cur;
            s[i] = tar - cur;
        } else {
            // number of rotations to get back to 0 mod arrs[i].size() then tar rotations
            rot += arrs[i].size() - cur + tar;
            s[i] = arrs[i].size() - cur + tar;
        }
    }

    cout << rot + arrs.size() << endl;
    for (int i = 0; i < arrs.size(); i++) {
        cout << 1 << " " << arrs[i].size() << endl;
        for (int j = 0; j < s[i]; j++) {
            cout << 2 << endl;
        }
    }

//    for (vector<int>& v: arrs) {
//        for (int j: v) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
}
