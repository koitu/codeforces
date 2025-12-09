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


typedef pair<long long, long long> ll;

long long siz(ll a, ll b) {
    long long x = abs(a.first - b.first) + 1;
    long long y = abs(a.second - b.second) + 1;
    return x * y;
}

vector<ll> pos;
bool valid(int i, int j) {
    // this is only called when there is a possibility to replace the current best
    //
    // make a box and check no lines passes through the box
    // the lines are always axis aligned

    
    long long left = min(pos[i].first, pos[j].first);
    long long right = max(pos[i].first, pos[j].first);
    long long down = min(pos[i].second, pos[j].second);
    long long up = max(pos[i].second, pos[j].second);

    const int n = pos.size();
    for (int x = 0; x < n; x++) {
        int y = (x + 1) % n;

        auto& xx = pos[x];
        auto& yy = pos[y];
        if (xx.first == yy.first) {
            // check if 
            long long cdown = min(xx.second, yy.second);
            long long cup = max(xx.second, yy.second);

            // line is within the left and right of the box
            // line also passes from outside to inside
            if (left < xx.first && xx.first < right && ((cdown <= down && down < cup) || (cdown < up && up <= cup))) {
                return false;
            }

        } else {
            long long cleft = min(xx.first, yy.first);
            long long cright = max(xx.first, yy.first);

            // line is within top and bottom of the box
            // line also passes from outside to inside
            if (down < xx.second && xx.second < up && ((cleft <= left && left < cright) || (cleft < right && right <= cright))) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string input_file = "input_a.txt";

    fstream file(input_file);
    string line;

    while (getline(file, line)) {
        vector<string> s = split(line, ",");
        pos.emplace_back(stoll(s[0]), stoll(s[1]));
    }

    const int n = pos.size();
    long long best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long nxt = siz(pos[i], pos[j]);
            if (nxt > best && valid(i, j)) {
                best = nxt;
            }
        }
    }

    cout << best << endl;
}

