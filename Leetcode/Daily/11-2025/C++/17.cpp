// Problem: 1437. Check If All 1's Are at Least Length K Places Away (Easy)
// Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (prev != -1 && i - prev <= k) return false;
                prev = i;
            }
        }

        return true;
    }
};