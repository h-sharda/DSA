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
        string num;
        cin >> num;

        int i = num.size() - 1;
        int ans = 0;
        while ( i >= 0 && num[i] == '0') i--, ans++;
        
        for (int j =0; j < i; j++) if (num[j] != '0') ans++;
        
        cout << ans << endl;

    }

    return 0;
}