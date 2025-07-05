// Problem: 1394. Find Lucky Integer in an Array (Easy)
// Link: https://leetcode.com/problems/find-lucky-integer-in-an-array

function findLucky(arr: number[]): number {
    const umap = new Map<number, number>();
    
    for (const i of arr) umap.set(i, (umap.get(i) || 0) + 1);
    
    let ans = -1;
    for (const [key, value] of umap.entries()) {
        if (key === value) ans = Math.max(ans, key);
    }
    
    return ans;
};