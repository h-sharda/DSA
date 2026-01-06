// Problem: 1975. Maximum Matrix Sum (Medium)
// Link: https://leetcode.com/problems/maximum-matrix-sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minn = INT_MAX, n = matrix.size(), neg = 0;
        long long ans = 0;

        for ( int i =0; i <  n ; i++){
            for ( int j =0; j < n; j++){
                if ( matrix[i][j] < 0 ){
                    neg++;
                    matrix[i][j] = -matrix[i][j];
                }
                minn = min(minn, matrix[i][j]);
                ans += matrix[i][j];
            }
        }

        return (neg % 2) ? ans - 2 * minn : ans;
    }
};