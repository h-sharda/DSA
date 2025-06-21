// Problem: 3085. Minimum Deletions to Make String K-Special (Medium)
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

class Solution {
    public int minimumDeletions(String word, int k) {
        int[] freq = new int[26];
        int n = word.length();

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) freq[word.charAt(i) - 'a']++;
        
        Arrays.sort(freq);

        for (int i = 25; i >= 0; i--) {
            int temp = 0;
            for (int j = i-1; j >= 0; j--) {
                temp += freq[j];
            }
            int target = freq[i] + k;
            for (int j = i; j < 26; j++) {
                if (freq[j] <= target) continue;
                temp += freq[j] - target;
            }
            ans = Math.min(ans, temp);
        }

        return ans;        
    }
}