// Date: 12/01/2025
// Number: 2116. Check if a Parentheses String Can Be Valid (Medium)
// link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2) return false;

        int open = 0;
        for (int i =0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') open++;
            else {
                if (open == 0) return false;
                else open--;
            }
        }

        int close = 0;
        for (int i =n-1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') close++;
            else {
                if (close == 0) return false;
                else close--;
            }
        }        

        return true;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s, locked;
        cin >> s >> locked;
        Solution sol;
        cout << sol.canBeValid(s, locked) << endl;
    }
    return 0;
}