// Problem: 3201. Find the Maximum Length of Valid Subsequence I (Medium)
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        bool sign = nums[0] % 2;
        int odd = sign, even = !sign, alt = 1;
        
        for (int i = 1; i  < n; i++) {
            if (nums[i] % 2) odd++;
            else even++;

            if (nums[i] % 2 != sign) {
                alt++;
                sign = !sign;
            }
        }

        return max({odd, even, alt});
    }
};