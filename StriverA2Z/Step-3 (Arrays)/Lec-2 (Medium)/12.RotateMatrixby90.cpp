// Leetcode: 48. Rotate Image (Medium)
// link: https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
        
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> matrix[i][j];

        Solution ob;
        ob.rotate(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << matrix[i][j] << " ";
            cout << "\n";
        }      
    }
    return 0;
}