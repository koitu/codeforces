#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> c(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    // dijstra with priority (char, length)
    // since we can only move right or down we can also do dp -> choose smaller (char, length) pair

//    vector<vector<pair<char, int>>> dp(n, vector<pair<char, int>>(n, make_pair('Z', INT_MAX)));
//    dp[0][0] = make_pair('A', 1);
//    for (int i = 1; i < n; i++) {
//        dp[i][0] = make_pair(c[i][0], i + 1);
//        dp[0][i] = make_pair(c[0][i], i + 1);
//    }
//
//
//    for (int i = 1; i < n; i++) {
//        for (int j = 1; j < n; j++) {
//            dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
//            dp[i][j].first = c[i][j];
//            dp[i][j].second++;
//        }
//    }
//
//    cout << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << dp[i][j].second << " ";
//        }
//        cout << endl;
//    }
//
//    vector<char> res;
//    int i = n - 1;
//    int j = n - 1;
//    while (i > 0 || j > 0) {
//        res.push_back(c[i][j]);
//
//        if (i == 0) {
//            j--;
//        } else if (j == 0) {
//            i--;
//        } else {
//            if (dp[i-1][j] < dp[i][j-1]) {
//                i--;
//            } else {
//                j--;
//            }
//        }
//    }
//    res.push_back(c[0][0]);
//
//    reverse(res.begin(), res.end());
//    cout << string(res.begin(), res.end()) << endl;

    // rethink: all the paths from top left to the bottom right have the same distance (since we can only move right or down)
    // idea: priority queue with bfs (or set with tuples)

//    typedef tuple<char, int, int> iii;
//    set<iii> cur;
//    set<iii> nxt;
//
//    cur.insert(make_tuple(c[0][0], 0, 0));
//
//    const int end = n + n - 1;
//    vector<char> res;
//
//    for (int i = 0; i < end; i++) {
//        auto [a, x, y] = *cur.begin();
//        res.push_back(a);
//
//        for (auto [b, x, y]: cur) {
//            if (a != b) {
//                // greater so must break
//                break;
//            }
//
//            if (x + 1 < n) {
//                nxt.insert(make_tuple(c[x+1][y], x+1, y));
//            }
//            if (y + 1 < n) {
//                nxt.insert(make_tuple(c[x][y+1], x, y+1));
//            }
//        }
//
//        cur.clear();
//        swap(cur, nxt);
//    }
//
//    cout << string(res.begin(), res.end()) << endl;

    // too slow^^^
    // idea: along each diagonal we always want to get the lexicoally lowest unless it prevents us from getting the lowest on the previous diagonal
    // only the best ones reachable from the previous best ones can go foward
    // 
    // problem: this is easy to do if there are not that many best choices but what if there are many best choices...

    // idea: think of the grid as a graph where we cull the nodes when there is better and merge those that are the same
    // in the end we come back to bfs (but try to do it faster)

    typedef pair<int, int> ii;
    vector<ii> cur;
    vector<ii> nxt;

    cur.reserve(3001);
    nxt.reserve(3001);

    vector<char> res;

    int end = n + n - 1;
    char best = 'Z';
    cur.emplace_back(0, 0);

    vector<vector<bool>> visited(n, vector<bool>(n, false));

//    cout << endl;

    for (int i = 0; i < end; i++) {
        for (const auto [x, y]: cur) {
            best = min(best, c[x][y]);

        }
        for (const auto [x, y]: cur) {
            char cc = c[x][y];
            if (cc != best) {
                continue;
            }

            // would a map of visited be faster here?
            if (x + 1 < n && !visited[x+1][y]) {
                visited[x+1][y] = true;
                nxt.emplace_back(x+1, y);
            }

            if (y + 1 < n && !visited[x][y+1]) {
                visited[x][y+1] = true;
                nxt.emplace_back(x, y+1);
            }
        }

//        cout << best << endl;
//        for (auto [x, y]: nxt) {
//            cout << x << " " << y << endl;
//        }
//        for (int x = 0; x < n; x++) {
//            for (int y = 0; y < n; y++) {
//                cout << (visited[x][y] ? 'x' : '.');
//            }
//            cout << endl;
//        }
//        cout << endl;
        
        res.push_back(best);
        best = 'Z';
        cur.clear();
        swap(cur, nxt);
    }
    
    cout << string(res.begin(), res.end()) << endl;
}

