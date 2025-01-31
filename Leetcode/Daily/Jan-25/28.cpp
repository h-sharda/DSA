// Date: 28/01/2025
// Number: 2658. Maximum Number of Fish in a Grid (Medium)
// link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    int dfs (vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) return 0;
        visited[x][y] = true;
        return grid[x][y] + dfs(grid, x, y + 1) +
               dfs(grid, x, y - 1) +
               dfs(grid, x + 1, y) +
               dfs(grid, x - 1, y);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>> (m, vector<bool>(n, false));

        int ans = 0;
        for ( int i = 0; i < m; i++) {
            for ( int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;        
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
        Solution sol;
        cout << sol.findMaxFish(grid) << endl;
    }
    
    return 0;
}
