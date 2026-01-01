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
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        int cycle = a + b + c;
        int ans = n/cycle;
        // cout << ans << " " << cycle << " ";
        int diff = n - ans*cycle;
        ans *= 3;
        // cout << ans << " " << diff << " ";
        if (diff > a+b ) ans += 3;
        else if (diff > a ) ans += 2;
        else if (diff > 0) ans += 1;

        cout << ans << endl;
    }
    return 0;
}