#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> powers;
vector<int> groups;
vector<int> nexth;
vector<int> bounces;

void update(const int a, const int b) {
    // update the current one then move backwards within the current group
    powers[a] = b;

    for (int i = a; i >= 0; i--) {
        if (groups[i] != groups[a]) {
            break;
        }

        int nxt = i + powers[i];
        if (nxt >= n || groups[i] != groups[nxt]) {
            nexth[i] = nxt;
            bounces[i] = 1;
        } else {
            nexth[i] = nexth[nxt];
            bounces[i] = bounces[nxt] + 1;
        }
    }
}

int res;
int get(const int a) {
    // this doesn't have to be recursion
    if (nexth[a] >= n) {
        int i = a;
        while (powers[i] + i < n) {
            i += powers[i];
        }
        res = i;

        return bounces[a];
    }

    return bounces[a] + get(nexth[a]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;
    const int sqrtn = sqrt(n);

    powers = vector<int>(n);
    groups = vector<int>(n);
    nexth = vector<int>(n, 0);
    bounces = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
        groups[i] = i / sqrtn;
    }

    for (int i = n - 1; i >= 0; i--) {
        int nxt = i + powers[i];

        if (nxt >= n || groups[i] != groups[nxt]) {
            nexth[i] = nxt;
            bounces[i] = 1;
        } else {
            nexth[i] = nexth[nxt];
            bounces[i] = bounces[nxt] + 1;
        }
    }

    int v, a, b;
    for (int i = 0; i < m; i++) {
        cin >> v;
        if (v == 0) {
            cin >> a >> b;
            // set power of hole a to b
            update(a-1, b);

        } else {
            cin >> a;
            // how many bounces until a goes out
            int bounce = get(a-1);
            cout << res + 1 << " " << bounce << endl;
        }
    }
}
