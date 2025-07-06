// Problem: 1865. Finding Pairs With a Certain Sum (Medium)
// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
public:
    vector<int> v;
    unordered_map<int, int> umap1, umap2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int &i: nums1) umap1[i]++;
        for (int &i: nums2) umap2[i]++;

        v = nums2;
    }
    
    void add(int index, int val) {
        umap2[v[index]]--;
        v[index] += val;
        umap2[v[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;

        for (auto &it: umap1) {
            if (umap2.contains(tot - it.first)) {
                ans += it.second * umap2[tot-it.first];
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */