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
        int n = 0;
        cin >> n;

        if ( n % 2 ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}