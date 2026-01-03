// Problem: 1267. Count Servers that Communicate (Medium)
// Link: https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> rows(m, 0), cols(n, 0);

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (grid[i][j]) rows[i]++, cols[j]++;
            }
        }

        int comm = 0;
        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) comm++;
            }
        }        

        return comm;
    }
};