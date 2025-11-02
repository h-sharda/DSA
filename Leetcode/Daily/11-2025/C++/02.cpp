// Problem: 2257. Count Unguarded Cells in the Grid (Medium)
// Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) { 
        vector<vector<char>> grid(m, vector<char> (n, '.'));
        int ans = m*n;

        for ( const auto &it: guards){
            grid[it[0]][it[1]] = 'G';
            ans--;
        }
        
        for ( const auto &it: walls){
            grid[it[0]][it[1]] = 'W';
            ans--;
        }

        for ( int i =0; i< m ; i++){
            for ( int j =0; j< n; j++){
                if ( grid[i][j] == 'G'){
                    for ( int k = i-1; k>=0 ; k--) {
                        if (grid[k][j] == '.' ) grid[k][j] = 'R';
                        else if ( grid[k][j] == 'R' ) continue;
                        else break;
                        ans--;
                    }
                    for ( int k = i+1; k < m ; k++) {
                        if (grid[k][j] == '.' ) grid[k][j] = 'R';
                        else if ( grid[k][j] == 'R' ) continue;
                        else break;
                        ans--;
                    }
                    for ( int k = j-1; k>=0 ; k--) {
                        if (grid[i][k] == '.' ) grid[i][k] = 'R';
                        else if ( grid[i][k] == 'R' ) continue;
                        else break;
                        ans--;
                    }
                    for ( int k = j+1; k < n ; k++) {
                        if (grid[i][k] == '.' ) grid[i][k] = 'R';
                        else if ( grid[i][k] == 'R' ) continue;
                        else break;
                        ans--;
                    }
                }
            }
        }

        return ans;
    }
};