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
        int n, d;
        cin >> n >> d;
 
        cout << "1 ";
 
        if ( d % 3 == 0 ) cout << "3 ";
        else if (n >= 3) cout << "3 ";
 
        if ( d == 5) cout << "5 ";
 
        if (d == 7) cout << "7 " ;
        else if ( n >= 3 ) cout << "7 ";
 
        if ( d == 9 ) cout << "9 ";
        else if (d % 3 == 0 && n >= 3) cout << "9 ";
        else if (n >= 6) cout << "9 ";
 
        cout << endl;
    }
 
    return 0;
}