// Problem: 1394. Find Lucky Integer in an Array (Easy)
// Link: https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> umap;
        
        for (int &i: arr) umap[i]++;
        
        int ans = -1;
        for (auto &it: umap) {
            if (it.first == it.second) ans = max(ans, it.first);
        }
        
        return ans;
    }
};