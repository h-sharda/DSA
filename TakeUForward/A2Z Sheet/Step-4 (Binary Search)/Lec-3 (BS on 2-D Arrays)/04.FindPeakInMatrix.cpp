// Leetcode: 1901. Find a Peak Element II (Medium)
// link: https://leetcode.com/problems/find-a-peak-element-ii/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int low = 0, high = n-1;

        while ( low <= high) {
            int mid = (low+high) / 2;

            int maxPos = 0;
            for (int i =0; i < m; i++) {
                if (mat[i][mid] > mat[maxPos][mid]) maxPos = i;
            }

            if (mid > 0 && mat[maxPos][mid-1] > mat[maxPos][mid]) high = mid -1;
            else if ( mid < n-1 && mat[maxPos][mid+1] > mat[maxPos][mid]) low = mid + 1;
            else return {maxPos, mid};
        }
        
        return {-1, -1};
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
        Solution ob;
        vector<int> ans = ob.findPeakGrid(matrix);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
