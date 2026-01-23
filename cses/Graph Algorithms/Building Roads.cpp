#include <bits/stdc++.h>
using namespace std;

struct disjointset {
    vector<int> p;

    disjointset(const int n) {
        p = vector<int>(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(const int a) {
        if (p[a] == a) {
            return a;
        }

        return p[a] = find(p[a]);
    }

    bool join(const int a, const int b) {
        int aa = find(a);
        int bb = find(b);
        if (aa == bb) {
            return false;
        }

        p[bb] = aa;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    disjointset ds(n);
    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        ds.join(a-1, b-1);
    }

    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (ds.join(0, i)) {
            res.push_back(i+1);
        }
    }

    cout << res.size() << endl;
    for (int i: res) {
        cout << 1 << " " << i << endl;
    }
}

