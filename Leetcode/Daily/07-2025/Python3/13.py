# Problem: 2410. Maximum Matching of Players With Trainers (Medium)
# Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        n, m = len(players), len(trainers)
        i, j, ans = 0, 0, 0

        while i < n and j < m:
            if players[i] <= trainers[j]:
                i += 1
                j += 1
                ans += 1
            else: 
                j += 1
        
        return ans