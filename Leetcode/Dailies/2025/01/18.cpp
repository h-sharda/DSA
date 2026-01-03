// Problem: 1368. Minimum Cost to Make at Least One Valid Path in a Grid (Hard)
// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
public:
    const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();

        deque<tuple<int, int, int>> dq;
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

        dq.emplace_back(0, 0, 0);
        visited[0][0] = 0;

        while (!dq.empty()) {
            auto [c, x, y] = dq.front();
            dq.pop_front();

            if (x == m-1 && y == n-1) return c;

            for (int i = 0; i < 4; i++) {
                int dx = x + dirs[i].first, dy = y + dirs[i].second;
                int extra = grid[x][y] == i + 1 ? 0 : 1;

                if (dx < 0 || dy < 0 || dx >= m || dy >= n || visited[dx][dy] <= c + extra) continue;

                visited[dx][dy]= c + extra;
                if (extra) dq.emplace_back(c + extra, dx, dy);
                else dq.emplace_front(c + extra, dx, dy);
            }
        }

        return -1;
    }
};