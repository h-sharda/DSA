# Problem: 2016. Maximum Difference Between Increasing Elements (Easy)
# Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n, maxx, ans = len(nums), 0, -1

        for val in nums[::-1]:
            if maxx > val:
                ans = max(ans, maxx - val)
            
            maxx = max(maxx, val)

        return ans