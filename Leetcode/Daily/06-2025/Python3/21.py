// Problem: 3085. Minimum Deletions to Make String K-Special (Medium)
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = [0] * 26
        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        freq.sort()
        ans = 2**31 -1
        
        for i in range(25, -1, -1):
            temp = 0
            for j in range(i-1, -1, -1):
                temp += freq[j]

            target = freq[i] + k
            for j in range(i, 26):
                if freq[j] <= target:
                    continue
                temp += freq[j] - target
            
            ans = min(ans, temp)
        

        return ans;        