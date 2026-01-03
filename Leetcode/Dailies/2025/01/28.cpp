// Problem: 2658. Maximum Number of Fish in a Grid (Medium)
// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

class Solution {
public:
    int m, n;
    
    int dfs (vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
        int temp = grid[x][y];
        grid[x][y] = 0;
        return temp + dfs(grid, x, y + 1) + dfs(grid, x, y - 1) + dfs(grid, x + 1, y) + dfs(grid, x - 1, y);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int ans = 0;
        for ( int i = 0; i < m; i++) {
            for ( int j = 0; j < n; j++) {
                if (grid[i][j] > 0) ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;        
    }
};