#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(string str){
    int n = str.size();
    int c2 = 0, c3 = 0, sum = 0;
    for ( int i = 0; i < n; i++) {
        sum += str[i]-'0';
        if ( str[i]-'0' == 2 ) c2++; 
        else if ( str[i]-'0' == 3 ) c3++;
    }

    if ( sum%9 == 0) return true;
    int diff = 9 - (sum%9);
    if ( diff == 1 && (c2 >= 5 || (c3 >= 1 && c2 >= 2))) return true;
    if ( diff == 2 && (c2 >= 1)) return true;
    if ( diff == 3 && (c2 >= 6 || (c3 >= 1 && c2 >= 3) || c3 >= 2)) return true;
    if ( diff == 4 && (c2 >= 2)) return true;
    if ( diff == 5 && (c2 >= 7 || (c3 >= 1 && c2 >= 4) || (c3 >= 2 && c2 >= 1))) return true;
    if ( diff == 6 && (c2 >= 3 || c3 >= 1)) return true;
    if ( diff == 7 && (c2 >= 8 || (c3 >= 1 && c2 >= 5) || (c3 >= 2 && c2 >= 2))) return true;
    if ( diff == 8 && (c2 >= 4 || (c3 >= 1 && c2 >= 1))) return true;

    return false;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if ( isValid(str) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}