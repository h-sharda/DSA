// Problem: 3440. Reschedule Meetings for Maximum Free Time II (Medium)
// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii

class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = endTime.length, ans = 0;
        int maxGap = 0;

        for (int i = 0; i < n; i++) {
            int prev = i == 0 ? 0 : endTime[i - 1];
            int next = i == n-1 ? eventTime : startTime[i + 1];

            int event = endTime[i] - startTime[i];
            int left = startTime[i] - prev;
            int right = next - endTime[i];

            if (event <= maxGap) ans = Math.max(ans, next - prev);
            else ans = Math.max(ans, left + right);
            
            maxGap = Math.max(maxGap, left);
        }

        maxGap = 0;
        for (int i = n-1; i >= 0; i--) {
            int prev = i == 0 ? 0 : endTime[i - 1];
            int next = i == n-1 ? eventTime : startTime[i + 1];

            int event = endTime[i] - startTime[i];
            int left = startTime[i] - prev;
            int right = next - endTime[i];

            if (event <= maxGap) ans = Math.max(ans, next - prev);
            else ans = Math.max(ans, left + right);
            
            maxGap = Math.max(maxGap, right);
        }

        return ans;        
    }
}
