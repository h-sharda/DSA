// Problem: 1751. Maximum Number of Events That Can Be Attended II (Hard)
// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

function maxValue(events: number[][], k: number): number {
    events.sort((a, b) => a[0] - b[0]);
    
    const n = events.length;
    const dp = Array.from({ length: n }, () => Array(k + 1).fill(-1));

    function next(i: number): number {
        const minn = events[i][1] + 1;

        let low = i + 1, high = n-1;
        let ans = n;

        while (low <= high) {
            
            const mid = Math.floor(low + (high - low) / 2);

            if (events[mid][0] >= minn) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    function r(i: number, k: number): number {
        if (k === 0 || i === n) return 0;

        if (dp[i][k] !== -1) return dp[i][k];

        let a = r(i + 1, k);
        let b = events[i][2] + r(next(i), k-1);

        return dp[i][k] = Math.max(a, b);
    };

    return r(0, k);
};
