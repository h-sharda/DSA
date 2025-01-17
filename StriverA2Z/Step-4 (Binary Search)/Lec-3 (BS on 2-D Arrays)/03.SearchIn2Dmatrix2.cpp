// Leetcode: 240. Search a 2D Matrix II (Medium)
// link: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int i = 0, j = n-1;

        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }

        return false;
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
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        int target;
        cin >> target;
        Solution ob;
        cout << ob.searchMatrix(matrix, target) << endl;
    }
    return 0;
}