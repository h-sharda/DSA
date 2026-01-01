// Leetcode: 125. Valid Palindrome (Easy)
// link: https://leetcode.com/problems/valid-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid(char &ch) {
        if (ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
        return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }

    bool check(string &s, int i, int j) {
        if ( i >= j ) return true;
        
        if (!isValid(s[i])) return check(s, i+1, j);
        if (!isValid(s[j])) return check(s, i, j-1);

        if (s[i] != s[j]) return false;
        return check(s, i+1, j-1);
    }

    bool isPalindrome(string s) {
        return check(s, 0, s.size()-1);
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.isPalindrome(s) << endl;      
    }
    return 0;
}