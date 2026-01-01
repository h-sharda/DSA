#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_io();
    string S , T;
    cin >> S >> T;
    int n = S.size(), m = T.size();

    vector<int> v1(26, -1), v2(26, -1);

    for ( int i = 1; i < n; i++) {
        int pos = S[i]-'a';
        if ( v1[pos] == -1 ) v1[pos] = i;
    }
    for ( int i = m-2; i >= 0; i--) {
        int pos = T[i]-'a';
        if ( v2[pos] == -1 ) v2[pos] = i;
    }
    
    int minLen = INT_MAX, ch = -1;
    for ( int i = 0; i < 26; i++) {
        if (v1[i] != -1 && v2[i] != -1) {
            int len = v1[i] + m - v2[i];
            if ( len < minLen ) {
                minLen = len;
                ch = i;
            }
        }
    }

    if ( ch == -1) {
        cout << -1;
        return 0;
    }
    
    string ans;
    for ( int i = 0; i < v1[ch]; i++) ans.push_back(S[i]);
    for ( int i = v2[ch]; i < m; i++) ans.push_back(T[i]);
    cout << ans;

    return 0;
}