# Problem: 3307. Find the K-th Character in String Game II (Hard)
# Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii

class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        ops = 0
        i = 0

        while k % 2 == 0:
            ops += operations[i]
            i += 1
            k //= 2

        i += 1
        k //= 2

        while k > 0:
            if k % 2 == 1:
                ops += operations[i]
            i += 1
            k //= 2

        return chr(ops % 26 + ord('a'))