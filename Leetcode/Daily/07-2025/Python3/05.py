# Problem: 1394. Find Lucky Integer in an Array (Easy)
# Link: https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        umap = {}
        
        for i in arr: 
            umap[i] = umap.get(i, 0) + 1
        
        ans = -1
        for key, value in umap.items():
            if key == value: 
                ans = max(ans, key)
        
        return ans