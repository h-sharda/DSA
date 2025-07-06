# Problem: 1865. Finding Pairs With a Certain Sum (Medium)
# Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.v = []
        self.umap1 = {}
        self.umap2 = {}

        for i in nums1:
            self.umap1[i] = self.umap1.get(i, 0) + 1
        
        for i in nums2:
            self.umap2[i] = self.umap2.get(i, 0) + 1

        self.v = nums2
                

    def add(self, index: int, val: int) -> None:
        self.umap2[self.v[index]] -= 1
        self.v[index] += val
        self.umap2[self.v[index]] = self.umap2.get(self.v[index], 0) + 1
                

    def count(self, tot: int) -> int:
        ans = 0

        for key in self.umap1:
            if tot - key in self.umap2:
                ans += self.umap1[key] * self.umap2[tot - key]

        return ans
        


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)