// Input Format: N = 3
// Result: 
// 1
// 2 3
// 4 5 6

// Input Format: N = 6
// Result:   
// 1
// 2  3
// 4  5  6
// 7  8  9  10
// 11  12  13  14  15
// 16  17  18  19  20  21

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
        int count = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << count++ << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}