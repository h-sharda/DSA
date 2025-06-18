// Problem: 2966. Divide Array Into Arrays With Max Difference (Medium)
// Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans(n/3);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3) {
            if (nums[i+2] - nums[i] > k) return {};
            ans[i/3] = {nums[i], nums[i+1], nums[i+2]};
        }

        return ans;
    }
};