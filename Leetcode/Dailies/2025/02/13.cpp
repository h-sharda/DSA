// Problem: 3066. Minimum Operations to Exceed Threshold Value II (Medium)
// Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;        
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());

        while (pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            pq.push(x * 2 + y);
            ans++;
        }

        return ans;
    }
};