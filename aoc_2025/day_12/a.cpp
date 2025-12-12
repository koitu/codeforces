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

vector<vector<bool>> shapes;
vector<int> counts;
int yes = 0;
int maybe = 0;
void solve(int w, int h, const vector<int>& req) {
    // we will try to solve just for the input case
    // 0:
    // ###
    // ##.
    // #..
    // 
    // 1:
    // ##.
    // ###
    // #.#
    // 
    // 2:
    // ..#
    // .##
    // ##.
    // 
    // 3:
    // ###
    // #..
    // ###
    // 
    // 4:
    // #.#
    // ###
    // #.#
    // 
    // 5:
    // ..#
    // ###
    // ###

    int tot = 0;
    int cou = 0;
    for (int i = 0; i < 6; i++) {
        // cout << req[i] << " ";
        tot += req[i] * counts[i];
        cou += req[i];
    }
    // cout << endl;
    
    int x33 = 0;

    // 2x 0 -> 4x3
    // 2x 2 -> 4x3
    // 1x 0 and 1x 2 -> 4x3
    int x34 = req[0] + req[2];
    if (x34 & 1) {
        x34--;
        x33++;
    }
    x34 /= 2;
    cou -= (x34 * 2) / 3; // -> for each x34 we save 2/3 of a x33

    // 1x 1 and 1x 4 -> 5x3
    int x35 = min(req[1], req[4]);
    x33 += max(0, req[1] - x35) + max(0, req[4] - x35);
    cou -= x35 / 3; // -> for each x35 we save 1/3 of a x33

    // 2x 3 -> 4x4
    int x44 = req[3];
    if (x44 & 1) {
        x44--;
        x33++;
    }
    x44 /= 2;

    // cout << "3x3 " << x33 << "   ";
    // cout << "3x4 " << x34 << "   ";
    // cout << "3x5 " << x35 << "   ";
    // cout << "4x4 " << x44 << "   ";
    // cout << endl;

    // no (not enough space at all)
    if (tot > w * h) {
        return;
    }

    // it looks like this (somewhat dumb) heuristic is enough to solve on the input
    // bro, the sample was so misleading xD

    // yes (enough space for 3x3 for each present)
    // if ((w/3) * 3 * (h/3) * 3 > cou * 3 * 3) {
    if ((w/3) * (h/3) > cou) {
        yes++;
    } else {
        maybe++;
    }
}


int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    for (int i = 0; i < 6; i++) {
        getline(file, line);

        int count = 0;
        vector<bool> shape;
        for (int j = 0; j < 3; j++) {
            getline(file, line);
            for (char c: line) {
                shape.push_back(c == '#');
                count += c == '#';
            }
        }
        counts.push_back(count);
        shapes.push_back(shape);

        getline(file, line);
    }


    while (getline(file, line)) {
        vector<string> s = split(line, " ");
        string fst = s[0];
        vector<string> fs = split(fst.substr(0, fst.size()-1), "x");

        int w = stoi(fs[0]);
        int h = stoi(fs[1]);
        vector<int> req;
        for (int i = 1; i <= 6; i++) {
            req.push_back(stoi(s[i]));
        }

        solve(w, h, req);
        // break;
    }

    cout << maybe << endl;
    cout << yes << endl;
}

