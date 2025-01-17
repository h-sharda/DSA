// Leetcode: 118. Pascal's Triangle (Easy)
// Link: https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for (int i =0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
            }
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
        Solution obj;
        vector<vector<int>> ans = obj.generate(n);
        for (auto v : ans) {
            for (int x : v) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}