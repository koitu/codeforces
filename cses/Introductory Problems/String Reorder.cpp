#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // AAAABBZZZZZ
    // getting: ABZAZBZAZAZ
    // answer: ABZAZAZAZBZ

    vector<int> chars(26, 0);
    int n = 0;
    char c;

    // get the frequency of each letter
    while (cin.get(c) && c != '\n') {
        chars[c - 'A']++;
        n++;
    }

    // get the lowest letter that is not the same as the previous
    vector<char> res;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        bool good = false;

        for (int j = 0; j < 26; j++) {
            if (prev != j && chars[j] > 0) {
                chars[j]--;
                res.push_back(j + 'A');
                prev = j;
                good = true;
                break;
            }
        }

        if (!good) {
            break;
        }
    }

    // there could be one letter with still some freq left
    // there will not be two letters like this becuase they will cancel themself out
    char left;
    int leftv = 0;
    for (int i = 0; i < 26; i++) {
        if (chars[i] > 0) {
            left = i + 'A';
            leftv = chars[i];
        }
    }

    // if it is freq 0 then we are done!
    if (leftv == 0) {
        cout << string(res.begin(), res.end()) << endl;
        return 0;
    }

    // the last value should be 'left'
    // otherwise find the first location of the letter left
    int i = 0;
    for (; i < res.size(); i++) {
        if (res[i] == left) {
            break;
        }
    }

    // cout << left << " " << leftv << endl;
    // cout << string(res.begin(), res.end()) << endl;

    // move the rest of the string into the stack
    // we already know that this string will be will be a bunch of letters with left between it
    priority_queue<char, vector<char>, greater<char>> s;
    for (int j = i; j < res.size(); j++) {
        if (res[j] != left) {
            s.push(res[j]);
        }
    }

    // cout << string(res.begin(), res.end()) << endl;

    // if there are not enough left in res to space out leftv
    if (i - leftv < 0) {
        cout << -1 << endl;
        return 0;
    }

    // put a letter between each "left"
    for (int j = 1; j <= leftv; j++) {
        s.push(res[i - j]);
    }

    // move everything back to res
    vector<char> result;
    for (int j = 0; j < i - leftv; j++) {
        result.push_back(res[j]);
    }
    while (!s.empty()) {
        result.push_back(left);
        result.push_back(s.top()); s.pop();
    }
    result.push_back(left);

    cout << string(result.begin(), result.end()) << endl;

    // char c;
    // vector<char> res;
    // while (cin.get(c) && c != '\n') {
    //     res.push_back(c);
    // }

    // sort(res.begin(), res.end());

    // we want the lowest to be at the front
    // then the next lower to be interweaved until we reach the end
    //
    // AAABBBCCCDDD
    // ABABAB CCCDDD
    // ABABCACBC DDD
    // ABABCACDBDCD
    //
    // ABABABCDCDCD
    // +2 C
    // ABABACBCDCDCDC
    //
    // AAABBBCCCCCCDDD
    // ABABABCCCCCCDDD
    // ABABABCCCDCDCDC (extra flow goes backwards)
    // ABABCACBCDCDCDC
    // if we didn't fully saturate D then it would also flow backwards
    //
    // can we do something like backtracking for this or do we need to smarter?
    //
    // idea:
    // - flow the current letter into the next ones
    // - we can also store a letter between two ones
    // - if the letters are not fully saturated then continue flowing
    // - at the end once our flow goes out the flow goes backwards
    //
    // now how to actually implement this idea...
    // 
    // idea: 
    // - create the minimum string thing
    // - use two pointers
    // - i will point to the "from" and j will point to "to"
    // - i will iterate over while j will point to the first different char
    // - if i detects a dup (with i-1) swap i and j
    // - at the end we deal with the bunch of extra?
    
    // const int n = res.size();
    // cout << string(res.begin(), res.end()) << endl;

    // int i = 1;
    // int j = 1;
    // for (; i < n; i++) {
    //     if (res[i] == res[i-1]) {
    //         while (j < n && res[j] == res[i]) {
    //             j++;
    //         }

    //         if (j == n) {
    //             // time to go backwards
    //             stack<char> s;


    //             break;
    //         }

    //         swap(res[i], res[j]);
    //         j++;
    //     }
    // }

    // cout << j << endl;
    // cout << string(res.begin(), res.end()) << endl;
}

