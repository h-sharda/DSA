// Problem: 2435. Paths in Matrix Whose Sum Is Divisible by K (Hard)
// Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(K)));

        v[0][0][grid[0][0] % K]++;

        for (int i = 1; i < m; i++)
            for (int k = 0; k < K; k++)
                v[i][0][(k + grid[i][0]) % K] = v[i - 1][0][k];

        for (int j = 1; j < n; j++)
            for (int k = 0; k < K; k++)
                v[0][j][(k + grid[0][j]) % K] = v[0][j - 1][k];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                for (int k = 0; k < K; k++)
                    v[i][j][(k + grid[i][j]) % K] = (v[i - 1][j][k] + v[i][j - 1][k]) % MOD;

        return v[m - 1][n - 1][0];
    }
};