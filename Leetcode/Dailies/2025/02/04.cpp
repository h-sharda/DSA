// Problem: 1800. Maximum Ascending Subarray Sum (Easy)
// Link: https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;

        int sum  = nums[0], i = 1, n = nums.size();

        while ( i < n) {
            if (nums[i] > nums[i-1]) sum += nums[i];
            else {
                ans = max(ans, sum);
                sum  = nums[i];
            }
            i++;
        }

        ans = max(sum, ans);
        return ans;
    }
};