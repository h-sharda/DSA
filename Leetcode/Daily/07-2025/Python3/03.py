# Problem: 3304. Find the K-th Character in String Game I (Easy)
# Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class Solution:
    def kthCharacter(self, k: int) -> str:
        add = -1
        while k % 2 == 0:
            k //= 2
            add += 1

        while k > 0:
            if k % 2 == 1:
                add += 1
            k //= 2
        
        return chr((add % 26) + ord('a'))