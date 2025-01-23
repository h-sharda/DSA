// Date: 19/01/2025
// Number: 407. Trapping Rain Water II (Hard)
// link: https://leetcode.com/problems/trapping-rain-water-ii/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:    
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1} , {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size(), n = heightMap[0].size();
        int water = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = true;
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][n - 1] = true;
        }
        for (int i = 1; i < n - 1; i++) {
            pq.push({heightMap[0][i], 0, i});
            visited[0][i] = true;
            pq.push({heightMap[m - 1][i], m - 1, i});
            visited[m - 1][i] = true;
        }

        while ( !pq.empty()) {
            
            int value = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();

            for (int i =0; i < 4; i++) {
                int dx = x + dirs[i][0], dy = y + dirs[i][1];

                if (dx < 0 || dx > m-1 || dy < 0 || dy > n-1 || visited[dx][dy]) continue;

                if (heightMap[dx][dy] < value) {
                    water += value - heightMap[dx][dy];
                    heightMap[dx][dy] = value;
                }

                visited[dx][dy] = true;
                pq.push({heightMap[dx][dy], dx, dy});
            }
        }

        return water;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        Solution sol;
        cout << sol.trapRainWater(grid) << endl;
    }
    return 0;
}