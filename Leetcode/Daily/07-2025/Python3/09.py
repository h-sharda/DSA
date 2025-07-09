# Problem: 3439. Reschedule Meetings for Maximum Free Time I (Medium)
# Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:    
        n = len(endTime)
        duration = 0

        for i in range(k):
            duration += endTime[i] - startTime[i]
        
        if k == n: 
            return eventTime - duration
        
        ans = startTime[k] - duration

        for i in range(k, n - 1):
            duration += endTime[i] - startTime[i]
            duration -= endTime[i - k] - startTime[i - k]

            curr = startTime[i + 1] - endTime[i - k]
            ans = max(ans, curr - duration)

        duration += endTime[n - 1] - startTime[n - 1]
        duration -= endTime[n - 1 - k] - startTime[n - 1 - k]

        return max(ans, eventTime - endTime[n - 1 - k] - duration)