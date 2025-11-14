// Problem: 2536. Increment Submatrices by One (Medium)
// Link: https://leetcode.com/problems/increment-submatrices-by-one

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1));
        vector<vector<int>> ans(n, vector<int>(n));

        for (auto &it: queries) {
            int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
            
            diff[x1][y1]++;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y1]--;
            diff[x2 + 1][y2 + 1]++;            
        }

        ans[0][0] = diff[0][0];

        for (int i = 1; i < n; i++) ans[i][0] = diff[i][0] + ans[i-1][0];
        for (int j = 1; j < n; j++) ans[0][j] = diff[0][j] + ans[0][j-1];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] = diff[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            }
        }

        return ans;
    }
};