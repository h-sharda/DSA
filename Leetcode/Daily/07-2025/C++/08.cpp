// Problem: 1751. Maximum Number of Events That Can Be Attended II (Hard)
// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

class Solution {
public:
    vector<vector<int>> events;
    vector<vector<int>> dp;
    int n;

    int next(int i) {
        int minn = events[i][1] + 1;

        int low = i + 1, high = n-1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] >= minn) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int r(int i, int k) {
        if (k == 0 || i == n) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        int a = r(i + 1, k);
        int b = events[i][2] + r(next(i), k-1);

        return dp[i][k] = max(a, b);
    };

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();

        sort(events.begin(), events.end());
        this->events = events;

        dp.assign(n, vector<int>(k + 1, -1));

        return r(0, k);
    }
};