#include <bits/stdc++.h>
using namespace std;


vector<string> split(const string &s, const string &de) {
    vector<string> res;

    size_t cur = 0;
    size_t nxt;
    while ((nxt = s.find(de, cur)) != string::npos) {
        res.push_back(s.substr(cur, nxt - cur));
        cur = nxt + de.size();
    }
    res.push_back(s.substr(cur));

    return res;
}

// solve with bfs
int solve(const vector<vector<int>> &moves, const int goal) {
    queue<int> a;
    queue<int> b;
    a.push(0);

    int res = 0;
    set<int> s;

    while (true) {
        while (!a.empty()) {
            int c = a.front(); a.pop();
            if (c == goal) {
                return res;
            }
            if (s.count(c)) {
                continue;
            }
            s.insert(c);

            for (const vector<int> &move: moves) {
                int nxt = c;

                for (const int m: move) {
                    int bt = 1 << m;
                    if (nxt & bt) {
                        nxt -= bt;
                    } else {
                        nxt += bt;
                    }
                }

                b.push(nxt);
            }
        }

        swap(a, b);
        res++;
    }
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    // wtf this looks like a pain...

    int res = 0;
    while (getline(file, line)) {
        // input parsing...
        vector<string> cur = split(line, " ");

        int n = cur[0].size();

        // small enough that we can store the bits in an int
        int goal = 0;
        for (int i = 1; i < n - 1; i++) {
            if (cur[0][i] == '#') {
                goal += (1 << (i - 1));
            }
        }

        n = cur.size();
        vector<vector<int>> moves;
        for (int i = 1; i < n - 1; i++) {
            vector<int> move;

            for (string& idx: split(cur[i].substr(1, cur[i].size()-2), ",")) {
                move.push_back(stoi(idx));
            }

            moves.push_back(move);
        }

        // time to solve the problem!
        res += solve(moves, goal);
    }

    cout << res << endl;
}

