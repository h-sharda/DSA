// Problem: 3151. Special Array I (Easy)
// Link: https://leetcode.com/problems/special-array-i

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i-1] % 2) return false;
        }
        return true;
    }
};