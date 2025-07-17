// Problem: 3202. Find the Maximum Length of Valid Subsequence II (Medium)
// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

function maximumLength(nums: number[], k: number): number {
    let ans = 0;
    let n = nums.length;
    let v = new Array(k);
    
    for (let i = 0; i < k; i++) {
        v.fill(0);
        for (let j = 0; j < n; j++) {
            v[nums[j] % k] = (v[((i - nums[j]) % k + k ) % k] ?? 0) + 1;
            ans = Math.max(ans, v[nums[j] % k]);
        }
    }

    return ans;            
};
