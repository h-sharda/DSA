// Problem: 2200. Find All K-Distant Indices in an Array (Easy)
// Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const ans: number[] = [];
    const n = nums.length;
    let valid = 0;

    for (let i = 0; i < n; i++) {
        if (nums[i] === key) {
            const last = ans.length === 0 ? -1 : ans[ans.length - 1];
            for (let j = Math.max(last + 1, i-k); j < i; j++) {
                ans.push(j)
            }

            valid = k + 1;
        }

        if (valid > 0) ans.push(i);
        valid--;
    }

    return ans;
};
