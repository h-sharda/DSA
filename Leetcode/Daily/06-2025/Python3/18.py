# Problem: 2966. Divide Array Into Arrays With Max Difference (Medium)
# Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        
        n = len(nums)
        ans = []
        nums.sort()

        i = 0

        while i < n:
            if nums[i+2] - nums[i] > k:
                return []
            ans.append([nums[i], nums[i+1], nums[i+2]])

            i += 3

        return ans;        