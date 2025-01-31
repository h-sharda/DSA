// Date: 18/01/2025
// Number: 1368. Minimum Cost to Make at Least One Valid Path in a Grid (Hard)
// link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> price(m, vector<int>(n, INT_MAX));
        price[0][0] = 0;

        while (!pq.empty()) {

            array<int, 3> v = pq.top();
            int cost = v[0], x = v[1], y = v[2];
            pq.pop();

            if (price[x][y] != cost) continue;

            for (int dir = 0; dir < 4; dir++) {
                int dx = x + dirs[dir][0];
                int dy = y + dirs[dir][1];

                if (dx >= 0 && dx < m  && dy >= 0 && dy < n) {
                    
                    int dcost = cost + ((dir + 1) == grid[x][y]  ? 0 : 1);

                    if (price[dx][dy] > dcost) {
                        price[dx][dy] = dcost;
                        pq.push({dcost, dx, dy});
                    }
                }
            }                       
        }

        return price[m-1][n-1];
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
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        Solution sol;
        cout << sol.minCost(grid) << endl;
    }
    return 0;
}