// Problem: 2966. Divide Array Into Arrays With Max Difference (Medium)
// Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

function divideArray(nums: number[], k: number): number[][] {
    let n = nums.length;
    let ans: number[][] = [];

    nums.sort((a, b) => a-b);
    for (let i = 0; i < n; i += 3) {
        if (nums[i+2] - nums[i] > k) return [];
        ans.push([nums[i], nums[i+1], nums[i+2]]);
    }

    return ans;
};