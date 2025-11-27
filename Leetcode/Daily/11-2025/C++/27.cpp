// Problem: 3381. Maximum Subarray Sum With Length Divisible by K (Medium)
// Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> v(n + 1);
        
        for (int i = 0; i < n; i++) v[i + 1] = v[i] + nums[i];

        long long ans = LLONG_MIN;

        for (int i = 0; i < k; i++) {
            long long sum = 0;
            for (int j = i; j + k < n; j += k) {
                sum += v[j + k] - v[j];
                ans = max(ans, sum);
                if (sum < 0) sum = 0;
            }
        }

        return ans;
    }
};