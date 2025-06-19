// Problem: 2294. Partition Array Such That Maximum Difference Is K (Medium)
// Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

class Solution {
    public int partitionArray(int[] nums, int k) {
        int ans = 1, n = nums.length;
        Arrays.sort(nums);
        int curr = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] - curr > k)  {
                ans++;
                curr = nums[i];
            }
        }

        return ans;        
    }
}