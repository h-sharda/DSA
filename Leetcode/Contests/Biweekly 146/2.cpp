#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1E9 + 7;
    
    int countPathsWithXorValue(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));

        dp[0][0][grid[0][0]] = 1;

        for ( int i =0; i< m ; i++) {
            for ( int j = 0; j < n; j++) {
                for (int k = 0; k < 16; k++) {
                    if ( i< m-1 ) dp[i+1][j][k^grid[i+1][j]] += dp[i][j][k] % MOD;
                    if ( j< n-1 ) dp[i][j+1][k^grid[i][j+1]] += dp[i][j][k] % MOD;
                }
            }
        }

        return dp[m-1][n-1][K] % MOD;
    }
};