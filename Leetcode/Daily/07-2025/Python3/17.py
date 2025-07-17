# Problem: 3202. Find the Maximum Length of Valid Subsequence II (Medium)
# Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        n = len(nums)

        for i in range(k):
            v = [0] * k
            for j in range(n):
                v[nums[j] % k] = v[((i - nums[j]) % k + k ) % k] + 1
                ans = max(ans, v[nums[j] % k])

        return ans;         