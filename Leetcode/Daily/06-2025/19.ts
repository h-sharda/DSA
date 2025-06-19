// Problem: 2294. Partition Array Such That Maximum Difference Is K (Medium)
// Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

function partitionArray(nums: number[], k: number): number {
    let ans = 1, n = nums.length;
    nums.sort((a,b) => a - b);
    let curr = nums[0];

    for (let i = 1; i < n; i++) {
        if (nums[i] - curr > k)  {
            ans++;
            curr = nums[i];
        }
    }

    return ans;            
};
