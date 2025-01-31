// Date: 23/01/2025
// Number: 1267. Count Servers that Communicate (Medium)
// link: https://leetcode.com/problems/count-servers-that-communicate/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        vector<int> rows(m, 0), cols(n, 0);

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (grid[i][j]) rows[i]++, cols[j]++;
            }
        }

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) ans++;
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
        cout << solution.countServers(mat) << "\n";
    }
    return 0;
}
