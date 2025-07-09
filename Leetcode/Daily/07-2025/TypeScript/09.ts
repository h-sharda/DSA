// Problem: 3439. Reschedule Meetings for Maximum Free Time I (Medium)
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i

function maxFreeTime(eventTime: number, k: number, startTime: number[], endTime: number[]): number {
    const n = endTime.length;
    let duration = 0;

    for (let i = 0; i < k; i++) duration += endTime[i] - startTime[i];
    
    if (k === n) return eventTime - duration;
    
    let ans = startTime[k] - duration;

    for (let i = k; i < n - 1; i++) {
        duration += endTime[i] - startTime[i];
        duration -= endTime[i - k] - startTime[i - k];

        let curr = startTime[i + 1] - endTime[i - k];
        ans = Math.max(ans, curr - duration);
    }

    duration += endTime[n - 1] - startTime[n - 1];
    duration -= endTime[n - 1 - k] - startTime[n - 1 - k];

    return Math.max(ans, eventTime - endTime[n - 1 - k] - duration);     
};