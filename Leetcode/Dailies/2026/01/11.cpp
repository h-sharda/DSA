// Problem: 85. Maximal Rectangle (Hard)
// Link: https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack<pair<int,int>> st;

        for (int i = 0; i <= n; i++){
            int width = 0, height = i == n ? 0 : heights[i];
            if (!st.empty() && height <= st.top().first) {
                while (!st.empty() && height <= st.top().first) {
                    width += st.top().second;
                    ans = max(ans, st.top().first * width);
                    st.pop();
                }
            } 
            
            st.push({height, width + 1});
        }
        
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> v(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') v[j] = 0;
                v[j] += matrix[i][j] - '0';
            }
            ans = max(ans, largestRectangleArea(v));
        }

        return ans;
    }
};