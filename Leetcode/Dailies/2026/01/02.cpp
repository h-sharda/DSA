// Problem: 961. N-Repeated Element in Size 2N Array (Easy)
// Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-3; i++) if (nums[i] == nums[i+1] || nums[i] == nums[i+2] || nums[i] == nums[i+3]) return nums[i];

        if (nums[n-3] == nums[n-2] || nums[n-3] == nums[n-1]) return nums[n-3];
        return nums[n-1];
    }
};