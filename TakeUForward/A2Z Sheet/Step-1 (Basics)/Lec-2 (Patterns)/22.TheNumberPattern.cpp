// Input Format: N = 3
// Result: 
// 3 3 3 3 3 
// 3 2 2 2 3 
// 3 2 1 2 3 
// 3 2 2 2 3 
// 3 3 3 3 3

// Input Format: N = 6
// Result:   
// 6 6 6 6 6 6 6 6 6 6 6 
// 6 5 5 5 5 5 5 5 5 5 6 
// 6 5 4 4 4 4 4 4 4 5 6 
// 6 5 4 3 3 3 3 3 4 5 6 
// 6 5 4 3 2 2 2 3 4 5 6 
// 6 5 4 3 2 1 2 3 4 5 6 
// 6 5 4 3 2 2 2 3 4 5 6 
// 6 5 4 3 3 3 3 3 4 5 6 
// 6 5 4 4 4 4 4 4 4 5 6 
// 6 5 5 5 5 5 5 5 5 5 6 
// 6 6 6 6 6 6 6 6 6 6 6

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dist (int i, int j, int n) {
    return max(abs(i-n), abs(j-n)) + 1;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // top-left = (1, 1), centre = (n,n), bottom-right = (2*n-1, 2*n-1)

        for ( int i = 1; i <= 2*n-1; i++) {
            for ( int j = 1; j <= 2*n-1; j++) cout << dist(i, j, n) << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}