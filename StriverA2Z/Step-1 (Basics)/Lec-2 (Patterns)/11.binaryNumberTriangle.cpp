// Input Format: N = 3
// Result: 
// 1
// 01
// 101

// Input Format: N = 6
// Result:   
// 1
// 01
// 101
// 0101
// 10101
// 010101

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
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) cout << !((i+j)%2);
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}