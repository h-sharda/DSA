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
        int x, y;
        cin >> x >> y;
        bool ans = false;
        if ( x + 1 == y) ans = true;
        else if (x > y) {
            int diff = x - y;
            if ( (diff - 8) % 9 == 0 ) ans = true;
        }

        if ( ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
