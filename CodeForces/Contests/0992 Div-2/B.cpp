#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int solve (int n) {
    if ( n == 1) return 1;
    int num = 1, count = 1;
    
    while ( num < n) {
        num = (num+1)*2;
        count++;
    }

    return count;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = solve(n);
        cout << ans << endl;
    }
    return 0;
}