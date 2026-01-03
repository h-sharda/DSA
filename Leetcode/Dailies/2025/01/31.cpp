// Problem: 827. Making A Large Island (Hard)
// Link: https://leetcode.com/problems/making-a-large-island

class Solution {
public:
    int n, pos;

    const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> region;
    vector<int> areas;

    void bfs(vector<vector<int>> &grid, int i, int j) {
        int A = 0;
        region[i][j] = pos;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            A++;

            for (const auto &it: dirs) {
                int dx = x + it[0], dy = y + it[1];
                if (dx < 0 || dy < 0 || dx >= n || dy >= n || !grid[dx][dy] || region[dx][dy] != -1) continue;

                region[dx][dy] = pos;
                q.push({dx, dy});
            }
        }

        areas.push_back(A);
        pos++;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), pos = 0;

        region = vector<vector<int>> (n, vector<int> (n, -1));

        for (int i = 0; i < n; i++) {
            for (int j =0; j < n; j++) {
                if ( grid[i][j] && region[i][j] == -1) bfs(grid, i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j =0; j < n; j++) {
                int sum = 0;

                if ( grid[i][j] ) sum = areas[region[i][j]];
                else {
                    unordered_set<int> seen;
                    sum++;
                    for (const auto &it: dirs) {
                        int dx = i + it[0], dy = j + it[1];
                        if (dx < 0 || dy < 0 || dx >= n || dy >= n ) continue;
                        if (region[dx][dy] == -1 || seen.contains(region[dx][dy])) continue;
                        
                        seen.insert(region[dx][dy]);
                        sum += areas[region[dx][dy]];
                    }
                } 

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};