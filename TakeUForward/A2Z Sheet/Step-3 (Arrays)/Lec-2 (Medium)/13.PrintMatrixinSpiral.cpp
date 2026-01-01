// Leetcode: 54. Spiral Matrix (Medium)
// Link: https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int up = 0, down = m-1, left = 0, right = n-1, x = 0, y = 0;

        vector<int> ans;

        while (ans.size() < n * m) {
            while (y <= right && x >= up && x <= down) ans.push_back(matrix[x][y++]);
            x++, y--, up++;

            while (x <= down && y <= right && y >= left) ans.push_back(matrix[x++][y]);
            x--, y--, right--;
            
            while (y >= left && x >= up && x <= down) ans.push_back(matrix[x][y--]);
            x--, y++, down--;

            while (x >= up && y <= right && y >= left) ans.push_back(matrix[x--][y]);
            x++, y++, left++;
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
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                cin >> matrix[i][j];
        
        Solution sol;
        vector<int> ans = sol.spiralOrder(matrix);
        for (int i = 0; i < ans.size(); i++) 
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}