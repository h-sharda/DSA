// Problem: 3202. Find the Maximum Length of Valid Subsequence II (Medium)
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

class Solution {
    public int maximumLength(int[] nums, int k) {
        int ans = 0;
        int n = nums.length;
        
        for (int i = 0; i < k; i++) {
            int[] v = new int[k];
            for (int j = 0; j < n; j++) {
                v[nums[j] % k] = v[((i - nums[j]) % k + k ) % k] + 1;
                ans = Math.max(ans, v[nums[j] % k]);
            }
        }

        return ans;        
    }
}
