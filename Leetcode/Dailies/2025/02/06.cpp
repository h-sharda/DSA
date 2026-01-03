// Problem: 1726. Tuple with Same Product (Medium)
// Link: https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                umap[nums[i] * nums[j]]++;

        int ans = 0;
        for (auto& [prod, freq] : umap)
            ans += freq * (freq - 1) * 4;

        return ans;
    }
};