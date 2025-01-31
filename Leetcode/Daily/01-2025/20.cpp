// Date: 20/01/2025
// Number: 2661. First Completely Painted Row or Column (Medium)
// link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<pair<int, int>> v(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[mat[i][j]] = {i, j};
            }
        }

        vector<int> v1(m, n), v2(n, m);
        for (int i = 0; i < m * n; i++) {
            if ((--v1[v[arr[i]].first]) == 0 || (--v2[v[arr[i]].second]) == 0) return i;
        }

        return -1;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        
        vector<int> arr(m * n);
        for (int i = 0; i < m * n; i++)     cin >> arr[i];
        
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) cin >> mat[i][j];
        
        Solution solution;
        cout << solution.firstCompleteIndex(arr, mat) << "\n";        
    }
    
    return 0;
}