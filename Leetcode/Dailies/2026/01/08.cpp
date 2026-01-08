// Problem: 1458. Max Dot Product of Two Subsequences (Hard)
// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int r(int I, int J, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &memo) {
        int n = nums1.size(), m = nums2.size();
        if (I == n || J == m) return INT_MIN;        
        if (memo[I][J] != INT_MIN) return memo[I][J];

        int a = nums1[I] * nums2[J];
        int b = r(I + 1, J + 1, nums1, nums2, memo);
        int c = r(I + 1, J, nums1, nums2, memo);
        int d = r(I, J + 1, nums1, nums2, memo);

        return memo[I][J] = max({a + max(0, b), c, d});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> memo(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        return r(0, 0, nums1, nums2, memo);
    }
};