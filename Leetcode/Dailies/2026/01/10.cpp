// Problem: 712. Minimum ASCII Delete Sum for Two Strings (Medium)
// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int r(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
        int n = s1.size(), m = s2.size();
        if (memo[i][j] != -1) return memo[i][j];
        
        if (i == n && j == m) return 0;        
        if (i == n) return memo[i][j] = s2[j] + r(i, j + 1, s1, s2, memo);
        if (j == m) return memo[i][j] = s1[i] + r(i + 1, j, s1, s2, memo);        

        if (s1[i] == s2[j]) return memo[i][j] = r(i + 1, j + 1, s1, s2, memo);

        return memo[i][j] = min(s1[i] + r(i + 1, j, s1, s2, memo), s2[j] + r(i, j + 1, s1, s2, memo));
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> memo(s1.size() + 1, vector<int> (s2.size() + 1, -1));
        
        return r(0, 0, s1, s2, memo);
    }
};