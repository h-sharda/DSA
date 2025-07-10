# Problem: 3440. Reschedule Meetings for Maximum Free Time II (Medium)
# Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(endTime)
        ans = 0
        maxGap = 0

        for i in range(n):
            prev = 0 if i == 0 else endTime[i - 1]
            next = eventTime if i == n-1 else startTime[i + 1]

            event = endTime[i] - startTime[i]
            left = startTime[i] - prev
            right = next - endTime[i]

            ans = max(ans, next - prev if event <= maxGap else left + right)
            maxGap = max(maxGap, left)

        maxGap = 0
        for i in range(n-1, -1, -1):
            prev = 0 if i == 0 else endTime[i - 1]
            next = eventTime if i == n-1 else startTime[i + 1]

            event = endTime[i] - startTime[i]
            left = startTime[i] - prev
            right = next - endTime[i]

            ans = max(ans, next - prev if event <= maxGap else left + right)
            maxGap = max(maxGap, right)

        return ans;         