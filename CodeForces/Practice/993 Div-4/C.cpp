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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        
        int seatA = min(m, a);
        int seatB = min(m, b);
        int seatC = min(2*m - seatA - seatB, c);

        int ans = seatA + seatB + seatC;
        cout << ans << endl;
    }
    return 0;
}