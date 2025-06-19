# Problem: 2294. Partition Array Such That Maximum Difference Is K (Medium)
# Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, n, curr = 1, len(nums), nums[0]
        
        i = 1
        while i < n:
            if (nums[i] - curr) > k:
                ans += 1
                curr = nums[i]
            i += 1        

        return ans;                