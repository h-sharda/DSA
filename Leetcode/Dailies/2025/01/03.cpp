// Problem: 2270. Number of Ways to Split Array (Medium)
// Link: https://leetcode.com/problems/number-of-ways-to-split-array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL), curr = 0;

        int n = nums.size(), ans = 0;

        for (int i =0; i < n-1; i++) {
            curr += nums[i];
            sum -= nums[i];

            if (curr >= sum) ans++;
        }

        return ans;
    }
};