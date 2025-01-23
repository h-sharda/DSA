// Date: 21/01/2025
// Number: 2017. Grid Game (Medium)
// link: https://leetcode.com/problems/grid-game/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long sum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL), sum2 = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            sum1 -= grid[0][i];
            ans = min (ans, max(sum1, sum2));
            sum2 += grid[1][i];
        }

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(2, vector<int>(n));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n; j++) cin >> grid[i][j];

        Solution solution;
        cout << solution.gridGame(grid) << "\n";
    }
    
    return 0;
}