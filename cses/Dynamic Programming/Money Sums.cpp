#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    // at each stage of the dp is all the coins we can make with the previous coins
    // max value is 100 x 1000 = 100,000 so our solution must be better than O(n^2)
    //
    // note: at each step it is possible to double the number of solutionso

    // const int end = 1e5 + 1;
    // vector<bool> dp(end, false);
    set<int, greater<int>> nums;
    nums.insert(0);

    for (int i = 0; i < n; i++) {
        // we can insert a value if it comes after the current one

        for (const int k: nums) {
            nums.insert(c[i] + k);
        }

//        for (const auto [k, v]: nums) {
//            cout << "(" << k << " " << v << ")  ";
//        }
//        cout << endl;
    }

    vector<int> res;
    for (const int k: nums) {
        res.push_back(k);
    }
    reverse(res.begin(), res.end());

    cout << res.size() - 1 << endl;
    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

