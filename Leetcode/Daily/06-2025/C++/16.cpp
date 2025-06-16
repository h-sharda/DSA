// Problem: 2016. Maximum Difference Between Increasing Elements (Easy)
// Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), maxx = 0, ans = -1;

        for (int i = n-1; i >= 0; i--) {
            if (maxx > nums[i]) ans = max(ans, maxx - nums[i]);
            maxx = max(maxx, nums[i]);
        }

        return ans;
    }
};