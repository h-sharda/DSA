// Input Format: N = 3
// Result: 
// *****  
//  ***
//   *   
// 
// Input Format: N = 6
// Result:     
// ***********
//  *********
//   *******
//    ***** 
//     ***    
//      *

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
        for ( int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 1; j--) cout << " ";
            for (int j = 1; j <= 2*(n-i) + 1; j++) cout << "*";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}