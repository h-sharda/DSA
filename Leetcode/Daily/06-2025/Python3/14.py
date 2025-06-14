# Problem: 2566. Maximum Difference by Remapping a Digit (Easy)
# Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class Solution:
    def minMaxDifference(self, num: int) -> int:
        
        s = str(num)
        n = len(s)

        maxStr = s
        
        i = 0
        while i < n and s[i] == '9':
            i += 1
        if i < n:
            change = s[i]
            maxStr = s.replace(change, '9')

        change = s[0]
        minStr = s.replace(change, '0')

        return int(maxStr) - int(minStr)