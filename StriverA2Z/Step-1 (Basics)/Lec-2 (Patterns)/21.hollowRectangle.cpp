// Input Format: N = 3
// Result: 
// ***
// * *
// ***

// Input Format: N = 6
// Result:   
// ******
// *    *
// *    *
// *    *
// *    *
// ******

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
        for ( int i = 1; i <= n; i++) cout << "*";
        cout << endl;
        for ( int i = 1; i <= n-2; i++) {
            cout << "*";
            for ( int j = 1; j <= n-2; j++) cout << " ";
            cout << "*" << endl;
        }
        for ( int i = 1; i <= n; i++) cout << "*";
        cout << endl << endl;
    }
    return 0;
}