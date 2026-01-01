// Input Format: N = 3
// Result: 
//   A  
//  ABA 
// ABCBA


// Input Format: N = 6
// Result:   
//      A     
//     ABA    
//    ABCBA   
//   ABCDCBA  
//  ABCDEDCBA 
// ABCDEFEDCBA

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
            for (int j = 1; j <= n - i; j++) cout << " ";
            char ch = 'A';
            for (int j = 1; j <= i; j++) {
                cout << ch;
                ch++;
            }
            ch--;
            for (int j = 1; j < i; j++) {
                ch--;
                cout << ch;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}