# Problem: 1751. Maximum Number of Events That Can Be Attended II (Hard)
# Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        
        n = len(events)
        dp = [[-1] * (k + 1) for _ in range(n)]

        def next(i): 
            minn = events[i][1] + 1

            low = i + 1 
            high = n - 1
            ans = n

            while low <= high:
                mid = low + ((high - low) // 2)
                
                if events[mid][0] >= minn:
                    ans = mid
                    high = mid - 1
                else:
                    low = mid + 1

            return ans

        def r(i, k):
            if k == 0 or i == n:
                return 0

            if dp[i][k] != -1:
                return dp[i][k]

            a = r(i + 1, k)
            b = events[i][2] + r(next(i), k-1)

            dp[i][k] = max(a, b)
            return dp[i][k]

        return r(0, k)
