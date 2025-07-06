// Problem: 1865. Finding Pairs With a Certain Sum (Medium)
// Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
    v = [];
    umap1 = new Map<number, number>();
    umap2 = new Map<number, number>();

    constructor(nums1: number[], nums2: number[]) {
        for (let i of nums1) this.umap1.set(i, (this.umap1.get(i) || 0) + 1);
        for (let i of nums2) this.umap2.set(i, (this.umap2.get(i) || 0) + 1);

        this.v = nums2;
    }

    add(index: number, val: number): void {
        this.umap2.set(this.v[index], this.umap2.get(this.v[index]) - 1);
        this.v[index] += val;
        this.umap2.set(this.v[index], (this.umap2.get(this.v[index]) || 0) + 1);
    }

    count(tot: number): number {
        let ans = 0;

        for (let key of this.umap1.keys()) {
            if (this.umap2.has(tot - key)) {
                ans += this.umap1.get(key) * this.umap2.get(tot - key);
            }
        }

        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */