// Problem: 3439. Reschedule Meetings for Maximum Free Time I (Medium)
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i

class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = endTime.length;
        int duration = 0;

        for (int i = 0; i < k; i++) duration += endTime[i] - startTime[i];
        
        if (k == n) return eventTime - duration;
        
        int ans = startTime[k] - duration;

        for (int i = k; i < n - 1; i++) {
            duration += endTime[i] - startTime[i];
            duration -= endTime[i - k] - startTime[i - k];

            int curr = startTime[i + 1] - endTime[i - k];
            ans = Math.max(ans, curr - duration);
        }

        duration += endTime[n - 1] - startTime[n - 1];
        duration -= endTime[n - 1 - k] - startTime[n - 1 - k];

        return Math.max(ans, eventTime - endTime[n - 1 - k] - duration);        
    }
}
