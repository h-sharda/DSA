// Input Format: N = 3
// Result: 
// C
// B C
// A B C

// Input Format: N = 6
// Result:   
// F
// E F
// D E F
// C D E F
// B C D E F
// A B C D E F

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
            for (char j = 'A' + n - i; j <= 'A'+ n -1; j++) cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}