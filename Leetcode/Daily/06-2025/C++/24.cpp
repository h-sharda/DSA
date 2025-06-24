// Problem: 2200. Find All K-Distant Indices in an Array (Easy)
// Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> s;
        int n = nums.size();

        int valid = 0;
        
        for (int i = 0; i< n; i++) {
            if (nums[i] == key) valid = k + 1;
            if (valid > 0) s.insert(i);
            valid--;
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == key) valid = k + 1;
            if (valid > 0) s.insert(i);
            valid--;            
        }

        return vector<int> (s.begin(), s.end());
    }
};