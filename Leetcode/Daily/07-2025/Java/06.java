// Problem: 1865. Finding Pairs With a Certain Sum (Medium)
// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
    int[] v;
    HashMap<Integer, Integer> umap1 = new HashMap<>(), umap2 = new HashMap<>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        for (int i: nums1) umap1.put(i, umap1.getOrDefault(i, 0) + 1);
        for (int i: nums2) umap2.put(i, umap2.getOrDefault(i, 0) + 1);
        
        v = nums2;
    }
    
    public void add(int index, int val) {
        umap2.put(v[index], umap2.get(v[index]) - 1);
        v[index] += val;
        umap2.put(v[index], umap2.getOrDefault(v[index], 0) + 1);
    }
    
    public int count(int tot) {
        int ans = 0;

        for (int key: umap1.keySet()) {
            if (umap2.containsKey(tot - key)) {
                ans += umap1.get(key) * umap2.get(tot - key);
            }
        }

        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */