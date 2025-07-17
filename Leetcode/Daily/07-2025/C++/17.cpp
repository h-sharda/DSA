// Problem: 3202. Find the Maximum Length of Valid Subsequence II (Medium)
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < k; i++) {
            vector<int> v(k);
            for (int j = 0; j < n; j++) {
                v[nums[j] % k] = v[((i - nums[j]) % k + k ) % k] + 1;
                ans = max(ans, v[nums[j] % k]);
            }
        }

        return ans;
    }
};