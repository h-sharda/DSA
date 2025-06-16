// Problem: 2016. Maximum Difference Between Increasing Elements (Easy)
// Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length, maxx = 0, ans = -1;

        for (int i = n-1; i >= 0; i--) {
            if (maxx > nums[i]) ans = Math.max(ans, maxx - nums[i]);
            maxx = Math.max(maxx, nums[i]);
        }

        return ans;  
    }
}