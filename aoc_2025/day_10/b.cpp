#include <bits/stdc++.h>
#include "z3++.h"
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

bool check(const vector<int> &a, const vector<int> &b) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool valid(const vector<int> &state, const vector<int> &goal) {
    const int n = state.size();
    for (int i = 0; i < n; i++) {
        if (state[i] > goal[i]) {
            return false;
        }
    }
    return true;
}

// // solve with bfs
// int solve(const vector<vector<int>> &moves, const vector<int> &goal) {
//     queue<vector<int>> a;
//     queue<vector<int>> b;
// 
//     const int n = goal.size();
//     a.push(vector<int>(n, 0));
// 
//     int res = 0;
//     while (true) {
//         while (!a.empty()) {
//             vector<int> c = a.front(); a.pop();
//             if (check(c, goal)) {
//                 return res;
//             }
//             if (!valid(c, goal)) {
//                 continue;
//             }
// 
//             for (const vector<int> &move: moves) {
//                 vector<int> nxt(c.begin(), c.end());
// 
//                 for (const int m: move) {
//                     nxt[m]++;
//                 }
// 
//                 b.push(nxt);
//             }
//         }
// 
//         swap(a, b);
//         res++;
//     }
// }

// // need to rethink because bfs is much too slow
// // the core of this problem is similar to knapsack
// // - we have a bunch of possible moves and we want to find the minimum number of moves to get to a state
// // - order the moves in indecreasing size then find all the states
// int solve(const vector<vector<int>> &moves, const vector<int> &goal) {
//     // map of state and number of moves
//     map<vector<int>, int> a;
//     map<vector<int>, int> b;
// 
//     const int n = goal.size();
//     a[vector<int>(n, 0)] = 0;
// 
//     for (const vector<int>& move: moves) {
//         if (a.count(goal)) {
//             return a[goal];
//         }
// 
//         for (auto [c, d]: a) {
//             vector<int> cc(c.begin(), c.end());
// 
//             int m = 0;
//             while (valid(cc, goal)) {
//                 b[cc] = d + m;
// 
//                 for (int mov: move) {
//                     cc[mov]++;
//                 }
//                 m++;
//             }
//         }
// 
//         a.clear();
//         swap(a, b);
//     }
// 
//     return a[goal];
// }


// I looked at the solutions on reddit
// they said to just use a ILP solver... (they recommend z3)
int solve(const vector<set<int>> &moves, const vector<int> &goal) {
    z3::context c;

    const int gs = goal.size();
    const int ms = moves.size();

    // solve Ax = b for x int
    // system of equations:
    //  - for each x[j] we multiply moves[j]
    //  - want to make the sum of all the cols equal to goal
    vector<z3::expr> x;
    for (int i = 0; i < ms; i++) {
        x.push_back(c.int_const(to_string(i).c_str()));
    }

    z3::optimize opt(c);

    // ensure that all variables are above zero
    for (int i = 0; i < ms; i++) {
        opt.add(x[i] >= 0);
    }

    // solve such that system of equations equals goal
    // iterate over all the positions in goal
    for (int i = 0; i < gs; i++) {
        z3::expr b = c.int_val(0);

        // iterate over all the moves
        // check if taking the move will increment this position in goal
        for (int j = 0; j < ms; j++) {
            if (moves[j].count(i)) {
                b = b + x[j];
            }
        }

        opt.add(b == c.int_val(goal[i]));
    }

    // optimize the objective
    z3::expr obj = c.int_val(0);
    for (int i = 0; i < ms; i++) {
        obj = obj + x[i];
    }
    opt.minimize(obj);

    // run the solver and get the result
    if (opt.check() == z3::sat) {
        z3::model m = opt.get_model();

        z3::expr val = m.eval(obj);
        // cout << m.eval(obj) << endl;
        return val.get_numeral_int();
    }

    cout << "ERROR" << endl;
    return 0;
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

        int n = cur.size();

        // small enough that we can store the bits in an int
        vector<int> goal;
        for (string& val: split(cur[n-1].substr(1, cur[n-1].size()-2), ",")) {
            // cout << val << " ";
            goal.push_back(stoi(val));
        }
        // cout << endl;

        vector<set<int>> moves;
        for (int i = 1; i < n - 1; i++) {
            set<int> move;

            for (string& idx: split(cur[i].substr(1, cur[i].size()-2), ",")) {
                move.insert(stoi(idx));
            }

            moves.emplace_back(move);
        }

        // time to solve the problem!
        res += solve(moves, goal);
    }

    cout << res << endl;
}

