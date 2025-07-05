// Problem: 1394. Find Lucky Integer in an Array (Easy)
// Link: https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer, Integer> umap = new HashMap<>();
        
        for (int i: arr) umap.put(i, umap.getOrDefault(i, 0) + 1);
        
        int ans = -1;
        for (int key: umap.keySet()) {
            if (key == umap.get(key)) ans = Math.max(ans, key);
        }
        
        return ans;        
    }
}