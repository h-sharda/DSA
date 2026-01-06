// Problem: 2364. Count Number of Bad Pairs (Medium)
// Link: https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size(), total = (n * (n-1)) / 2;
        unordered_map<int, int> umap;
        
        for (int i =0; i < n; i++) {
            total -= umap[nums[i] - i];
            umap[nums[i] - i]++;
        }

        return total;
    }
};