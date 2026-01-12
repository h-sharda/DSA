// Problem: 1266. Minimum Time Visiting All Points (Easy)
// Link: https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int d(vector<int> &a, vector<int> &b) {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 1; i < n; i++) ans += d(points[i-1], points[i]);
        return ans;
    }
};