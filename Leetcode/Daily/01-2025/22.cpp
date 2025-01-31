// Date: 22/01/2025
// Number: 1765. Map of Highest Peak (Medium)
// link: https://leetcode.com/problems/map-of-highest-peak/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    const vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int> (n, -1));
        queue<int> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push(i * 1000 + j);
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int pos = q.front();
            int x = pos / 1000, y = pos % 1000;
            q.pop();

            for (int i =0; i < 4; i++) {
                int dx = x + dirs[i][0], dy = y + dirs[i][1];
                if (dx < 0 || dx > m-1 || dy < 0 || dy > n-1 || ans[dx][dy] != -1) continue;

                ans[dx][dy] = ans[x][y] + 1;
                q.push(dx * 1000 + dy);
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
        
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) cin >> mat[i][j];
        
        Solution solution;
        vector<vector<int>> ans = solution.highestPeak(mat);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
