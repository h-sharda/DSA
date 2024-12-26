// Input Format: N = 3
// Result: 
// A
// B B
// C C C

// Input Format: N = 6
// Result:   
// A 
// B B
// C C C
// D D D D
// E E E E E
// F F F F F F

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char ch = 'A';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << ch << " ";
            cout << endl;
            ch++;
        }
        cout << endl;
    }
    return 0;
}