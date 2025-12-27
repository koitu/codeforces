#include <bits/stdc++.h>
using namespace std;

constexpr int ri = 1;
constexpr int up = 1 << 1;
constexpr int le = 1 << 2;
constexpr int dow = 1 << 3;

int rotate_left(const int dir) {
    if (dir == ri) {
        return dow;
    }
    return dir >> 1;
}

int rotate_right(const int dir) {
    if (dir == dow) {
        return ri;
    }
    return dir << 1;
}

void next_pos(int &x, int &y, const int dir) {
    if (dir == ri) {
        y += 1;
    } else if (dir == up) {
        x += 1;
    } else if (dir == le) {
        y -= 1;
    } else {
        x -= 1;
    }
}


void solve() {
    int r, c;
    cin >> r >> c;

    int x_start, y_start;
    cin >> x_start >> y_start;

    int x_end, y_end;
    cin >> x_end >> y_end;

    x_start--;
    y_start--;
    x_end--;
    y_end--;

    vector<vector<char>> maze(r, vector<char>(c));
    vector<vector<int>> visit(r, vector<int>(c, 0)); // need to save visited and which direction we are facing when visit

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];

        }
    }

    int direction = ri;
    int x = x_start;
    int y = y_start;
    while (!(x == x_end && y == y_end)) {
//        cout << x << " " << y << " " << direction << endl;

        if (visit[x][y] & direction) {
            // found a loop: exit
            cout << 0 << endl;
            return;
        }
        visit[x][y] |= direction;

        int nx = x;
        int ny = y;
        // case 1: can we turn left 90 degrees to face an empty square?
        next_pos(nx, ny, rotate_left(direction));
        if (nx >= 0 && ny >= 0 && nx < r && ny < c && maze[nx][ny] == '0') {
            direction = rotate_left(direction);
            x = nx;
            y = ny;
            continue;
        }

        nx = x;
        ny = y;
        // case 2: can we move forward?
        next_pos(nx, ny, direction);
//        cout << nx << " " << ny << " " << direction << endl;
        if (nx >= 0 && ny >= 0 && nx < r && ny < c && maze[nx][ny] == '0') {
            x = nx;
            y = ny;
            continue;
        }

        // case 3: rotate 90 right
        direction = rotate_right(direction);
    }

    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
