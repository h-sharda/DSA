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
        string s;
        cin >> s;

        int i =0;
        int firstP = n, lastS = -1;

        for ( int i =0; i < n; i++) {
            if (s[i] == 'p') firstP = min(firstP, i);
            else if (s[i] == 's') lastS = max(lastS, i);
        }

        string ans = "YES";
        if ( lastS == -1 || firstP == n) ans = "YES";
        else {
            int startP = 0, endP = firstP;
            int startS = lastS, endS = n-1;
            if ( startP < startS && endS > endP) ans = "NO";
        }

        cout << ans << endl;
    }
    return 0;
}