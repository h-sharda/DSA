# Problem: 2200. Find All K-Distant Indices in an Array (Easy)
# Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        
        ans = []
        n = len(nums)
        valid = 0

        for i in range (n):
            if nums[i] == key:
                last = -1 if len(ans) == 0 else ans[-1]
                for j in range(max(last + 1, i-k), i):
                    ans.append(j)

                valid = k + 1

            if valid > 0:
                ans.append(i)

            valid -= 1
        

        return ans