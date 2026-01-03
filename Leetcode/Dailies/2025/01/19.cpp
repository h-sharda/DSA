// Problem: 407. Trapping Rain Water II (Hard)
// Link: https://leetcode.com/problems/trapping-rain-water-ii

class Solution {
public:
    const vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    int trapRainWater(vector<vector<int>>& ht) {
        int m = ht.size(), n = ht[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));

        int ans = 0;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;

        for (int i = 0; i < n; i++) visited[0][i] = true, pq.emplace(ht[0][i], 0, i);
        for (int i = 0; i < n; i++) visited[m-1][i] = true, pq.emplace(ht[m-1][i], m-1, i);
        for (int i = 1; i < m-1; i++) visited[i][0] = true, pq.emplace(ht[i][0], i, 0);
        for (int i = 1; i < m-1; i++) visited[i][n-1] = true, pq.emplace(ht[i][n-1], i, n-1);

        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            for (auto &it: dirs) {
                int dx = it[0] + x, dy = it[1] + y;
                if (dx < 0 || dx >= m || dy < 0 || dy >= n || visited[dx][dy]) continue;

                visited[dx][dy] = true;
                ans += max(0, h - ht[dx][dy]);
                pq.emplace(max(ht[dx][dy], h), dx, dy);
            }
        }

        return ans;
    }
};