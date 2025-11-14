// Problem: 2536. Increment Submatrices by One (Medium)
// Link: https://leetcode.com/problems/increment-submatrices-by-one

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n + 1));

        for (auto &it: queries) {
            int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
            for (int i = x1; i <= x2; i++) {
                ans[i][y1]++;
                ans[i][y2 + 1]--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) ans[i][j] += ans[i][j - 1];
            ans[i].pop_back();
        }

        return ans;
    }
};