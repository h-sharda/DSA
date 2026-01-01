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
        string str;
        cin >> str;
        
        int n = str.size();
        string ans(n, ' '); 
        for (int i =0; i < n; i++) {
            if ( str[i] == 'p') ans[n-i-1] = 'q';
            else if ( str[i] == 'q') ans[n-i-1] = 'p';
            else ans[n-1-i] = 'w';
        }

        cout << ans << endl;
    }
    return 0;
}