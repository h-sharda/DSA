// Problem: 2116. Check if a Parentheses String Can Be Valid (Medium)
// Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

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