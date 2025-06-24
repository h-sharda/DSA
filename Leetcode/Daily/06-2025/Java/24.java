// Problem: 2200. Find All K-Distant Indices in an Array (Easy)
// Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        int valid = 0;
        
        for (int i = 0; i< n; i++) {
            if (nums[i] == key) {
                int last = ans.isEmpty() ? -1 : ans.get(ans.size() - 1);
                for (int j = Math.max(last + 1, i-k); j < i; j++) {
                    ans.add(j);
                }

                valid = k + 1;
            }

            if (valid > 0) ans.add(i);
            valid--;
        }

        return ans;        
    }
}