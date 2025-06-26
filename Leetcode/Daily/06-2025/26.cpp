// Problem: 2311. Longest Binary Subsequence Less Than or Equal to K (Medium)
// Link: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') ans++;
        }
        
        int lim = min(n, 31);
        for (int i = 0; i < lim; i++) {
            if (s[n-i-1] == '1') {
                if (k - (1 << i) >= 0) {
                    ans++;
                    k -= 1 << i;
                }
            }
        }

        return ans;
    }
};