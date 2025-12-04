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



int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    getline(file, line);
    const int n = line.size() + 2;

    vector<string> grid;
    grid.push_back(string(n, '.'));
    grid.push_back("." + line + ".");

    while (getline(file, line)) {
        grid.push_back("." + line + ".");
    }

    grid.push_back(string(n, '.'));

    vector<pair<int, int>> d{
        {-1, 1},
        {-1, 0},
        {-1, -1},
        {0, 1},
        {0, -1},
        {1, 1},
        {1, 0},
        {1, -1},
    };

    const int m = grid.size();
    int res = 0;
    while (true) {
        bool removed = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sm = 0;

                if (grid[i][j] == '@') {
                    for (auto [dx, dy]: d) {
                        if (grid[i+dx][j+dy] == '@') {
                            sm += 1;
                        }
                    }

                    if (sm < 4) {
                        grid[i][j] = '.';
                        removed = true;
                        res++;
                    }
                }
            }
        }

        if (!removed) {
            break;
        }
    }

    cout << res << endl;
}

