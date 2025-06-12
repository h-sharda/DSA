// Problem: 3423. Maximum Difference Between Adjacent Elements in a Circular Array Easy
// Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(nums[i] - nums[(i + 1) % n]));
        }
        return ans;
    }
};