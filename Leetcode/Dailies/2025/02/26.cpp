// Problem: 1749. Maximum Absolute Sum of Any Subarray (Medium)
// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a = 0, b = 0, s1 = 0, s2 = 0;

        for (int &num: nums) {
            s1 += num;
            s1 = max(s1, 0);
            a = max(a, s1);

            s2 += num;
            s2 = min(s2, 0);
            b = min(b, s2);
        }

        return max(a, -b);
    }
};