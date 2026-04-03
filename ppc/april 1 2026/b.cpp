#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    // 3 4 5 YES
    // 3 4 6 NO
    // 7 24 25 YES
    // 6 20 21 NO
    // 10 10 10 NO
    
    long long a, b, c;
    cin >> a >> b >> c;
    if (a * a + b * b == c * c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
