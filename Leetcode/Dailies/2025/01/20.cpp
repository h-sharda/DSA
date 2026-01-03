// Problem: 2661. First Completely Painted Row or Column (Medium)
// Link: https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<pair<int, int>> v(m * n + 1);
        vector<int> rows(m), cols(n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                v[mat[i][j]] = {i, j};

        for (int i = 0; i < m * n; i++) {
            auto [row, col] = v[arr[i]];
            rows[row]++, cols[col]++;
            if (rows[row] == n || cols[col] == m) return i;
        }

        return -1;
    }
};