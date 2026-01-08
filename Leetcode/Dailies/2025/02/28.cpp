// Problem: 1092. Shortest Common Supersequence (Hard)
// Link: https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
    int r(string &str1, string &str2, int i, int j, vector<vector<int>> &memo) {
        int n = str1.size(), m = str2.size();
        if (i == n && j == m) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (i == n) return m - j;
        if (j == m) return n - i;

        if (str1[i] == str2[j]) return memo[i][j] = 1 + r(str1, str2, i + 1, j + 1, memo);
        int a = 1 + r(str1, str2, i + 1, j, memo);
        int b = 1 + r(str1, str2, i, j + 1, memo);

        return memo[i][j] = min(a, b);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        int len = r(str1, str2, 0, 0, memo);
        
        for (int i = 0; i <= n; i++) memo[i][m] = n - i;
        for (int j = 0; j <= m; j++) memo[n][j] = m - j;

        string ans;
        int i = 0, j = 0;

        while (i < n || j < m) {
            if (i == n) {
                ans += str2.substr(j);
                j = m;
            } else if (j == m) {
                ans += str1.substr(i);
                i = n;
            } else if (str1[i] == str2[j]) {
                ans.push_back(str1[i]);
                i++, j++;
            } else {
                if (memo[i + 1][j] < memo[i][j + 1]) ans.push_back(str1[i++]);
                else ans.push_back(str2[j++]);
            }
        }

        return ans;
    }
};