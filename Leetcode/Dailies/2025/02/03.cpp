// Problem: 3105. Longest Strictly Increasing or Strictly Decreasing Subarray (Easy)
// Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), i = 1;

        while (i < n) {
            if (nums[i-1] == nums[i]) i++;
            else if (nums[i-1] < nums[i]) {
                int len = 1;
                while (i < n && nums[i-1] < nums[i]) i++, len++;
                ans = max(ans, len);
            } else {
                int len = 1;
                while (i < n && nums[i-1] > nums[i]) i++, len++;
                ans = max(ans, len);
            }
        }

        return ans;
    }
};