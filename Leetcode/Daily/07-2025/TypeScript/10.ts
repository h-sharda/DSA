// Problem: 3440. Reschedule Meetings for Maximum Free Time II (Medium)
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii

function maxFreeTime(eventTime: number, startTime: number[], endTime: number[]): number {
    let n = endTime.length, ans = 0;
    let maxGap = 0;

    for (let i = 0; i < n; i++) {
        let prev = i == 0 ? 0 : endTime[i - 1];
        let next = i == n-1 ? eventTime : startTime[i + 1];

        let event = endTime[i] - startTime[i];
        let left = startTime[i] - prev;
        let right = next - endTime[i];

        if (event <= maxGap) ans = Math.max(ans, next - prev);
        else ans = Math.max(ans, left + right);
        
        maxGap = Math.max(maxGap, left);
    }

    maxGap = 0;
    for (let i = n-1; i >= 0; i--) {
        let prev = i == 0 ? 0 : endTime[i - 1];
        let next = i == n-1 ? eventTime : startTime[i + 1];

        let event = endTime[i] - startTime[i];
        let left = startTime[i] - prev;
        let right = next - endTime[i];

        if (event <= maxGap) ans = Math.max(ans, next - prev);
        else ans = Math.max(ans, left + right);
        
        maxGap = Math.max(maxGap, right);
    }

    return ans;    
};