// Problem: 2017. Grid Game (Medium)
// Link: https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long a = 0, b = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; i++) a += grid[0][i];

        for (int i = 0; i < n; i++) {
            a -= grid[0][i];

            ans = min(ans, max(a, b));

            b += grid[1][i];
        }

        return ans;
    }
};