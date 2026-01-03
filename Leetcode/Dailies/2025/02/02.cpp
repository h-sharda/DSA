// Problem: 1752. Check if Array Is Sorted and Rotated (Easy)
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool rotated = false;
        
        for (int i =1; i < n; i++) {
            if ( nums[i-1] > nums[i] ) {
                if (rotated) return false;
                else {
                    if (nums[0] < nums[n-1]) return false;
                    rotated = true;
                }
            }
        }

        return true;
    }
};