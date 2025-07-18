// Problem: 2163. Minimum Difference in Sums After Removal of Elements (Hard)
// Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> v(n + 1);
        priority_queue<int, vector<int>, greater<>> pq1;
        priority_queue<int> pq2;
        
        long long sum = 0;
        
        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            sum += nums[i];
            pq1.push(nums[i]);
        }
        
        for (int i = 2 * n - 1; i >= n-1; i--) {
            v[i - n + 1] = sum;
            
            sum += nums[i];
            pq1.push(nums[i]);
            
            sum -= pq1.top();
            pq1.pop();
        }

        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pq2.push(nums[i]);
        }

        long long ans = sum - v[0];

        for (int i = n; i < 2 *n; i++) {    
            sum += nums[i];
            pq2.push(nums[i]);
            
            sum -= pq2.top();
            pq2.pop();

            ans = min(ans, sum - v[i - n + 1]);
        }

        return ans;
    }
};