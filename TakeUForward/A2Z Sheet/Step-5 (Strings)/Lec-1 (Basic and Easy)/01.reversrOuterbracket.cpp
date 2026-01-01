// Leetcode: 1021. Reverse Outermost Parentheses (Easy)
// link: https://leetcode.com/problems/reverse-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.size(), i = 0, open = 0;
        while (i < n) {
            if (open == 0 && s[i] == '(') open++;
            else if (open == 1 && s[i] == ')') open--;
            else {
                ans.push_back(s[i]);
                if (s[i] == '(') open++;
                else open--;
            }
            i++;
        }
        return ans;
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
        cout << obj.removeOuterParentheses(s) << endl;
    }
    return 0;
}