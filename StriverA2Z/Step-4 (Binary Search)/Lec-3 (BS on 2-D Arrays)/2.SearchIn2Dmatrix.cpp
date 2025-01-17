// Leetcode: 74. Search a 2D Matrix (Medium)
// link: https://leetcode.com/problems/search-a-2d-matrix/

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
        int low = 0, high = m*n - 1;

        while (low <= high){
            int mid = low + (high-low)/2;
            if ( matrix[mid / n][mid % n] == target) return true;
            else if ( matrix[mid / n][mid % n] > target ) high = mid-1;
            else low = mid +1;
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