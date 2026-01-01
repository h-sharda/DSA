// Input Format: N = 3
// Result: 
// A B C
// A B
// A

// Input Format: N = 6
// Result:   
// A B C D E F
// A B C D E 
// A B C D
// A B C
// A B
// A

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
        for (int i = n; i >= 1; i--) {
            char ch = 'A';
            for (int j = 1; j <= i; j++) cout << ch++ << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}