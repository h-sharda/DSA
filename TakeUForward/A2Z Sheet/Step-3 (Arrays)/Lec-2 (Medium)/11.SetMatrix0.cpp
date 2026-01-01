// Leetcode: 73. Set Matrix Zeroes (Medium)
// link: https://leetcode.com/problems/set-matrix-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        bool setTopRow0 = false;
        for (int i =0; i < n; i++) if (matrix[0][i] == 0) setTopRow0 = true;
        for (int i =0; i < m; i++) if (matrix[i][0] == 0) matrix[0][0] = 0;

        for (int i =1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }

        for (int i =1; i < m; i++) {
            if (matrix[i][0] == 0) for (int j = 1; j < n; j++) matrix[i][j] = 0;
        }

        for (int i =0; i < n; i++) {
            if (matrix[0][i] == 0) for (int j = 1; j < m; j++) matrix[j][i] = 0;
        }

        if (setTopRow0) for (int i =0; i < n; i++) matrix[0][i] = 0;

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
        for (int i =0; i < m; i++) for (int j =0; j < n; j++) cin >> matrix[i][j];
        Solution sol;
        sol.setZeroes(matrix);
        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
        
    }
    return 0;
}