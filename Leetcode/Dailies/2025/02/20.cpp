// Problem: 1980. Find Unique Binary String (Medium)
// Link: https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, ' ');
        for (int i=0; i < n; i++) ans[i] = !(nums[i][i] - '0') + '0';
        return ans;
    }
};