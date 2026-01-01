#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string solve(string &s){
    int n = s.size();

    int i = n-1;
    while ( i > 0 ) {
        if ( s[i-1] < s[i]-1 ) {
            swap (s[i-1], s[i]);
            s[i-1]--;
            int pos = i;
            while ( pos < n && ( (s[pos]-'0') < (s[pos+1]-1-'0'))) {
                swap(s[pos], s[pos+1]);
                s[pos]--;
                pos++;
            }
        }
        i--;
    }
    return s;
}   

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    return 0;
}