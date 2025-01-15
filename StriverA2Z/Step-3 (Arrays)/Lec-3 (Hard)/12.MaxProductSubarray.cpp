// Leetcode: 152. Maximum Product Subarray (Medium)
// Link: https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:

    int cal (vector<int> &nums, int start, int end) {
        if ( start > end ) return INT_MIN;
        int prod = 1, firstNeg = -1, lastNeg = -1;

        for (int i = start; i <= end; i++) {
            prod *= nums[i];
            if (nums[i] < 0) {
                if (firstNeg == -1) firstNeg = i;
                lastNeg = i;
            }
        }

        if (prod < 0 && start != end) {
            int temp1 = prod, temp2= prod;
            if (firstNeg == start) temp1 = prod/nums[start];
            else for (int i = start; i <= firstNeg; i++) temp1 /= nums[i];

            if (lastNeg == start) temp2 = prod/nums[end];
            else for (int i = end; i >= lastNeg; i--) temp2 /= nums[i];

            prod = max(temp1, temp2);
        }

        return prod;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, start = 0, zeros = 0;

        for (int i =0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
                int val = cal(nums, start, i - 1);
                start = i + 1;
                ans = max(ans, val);
            }
        }

        ans = max(ans, cal(nums, start, n-1));
        if (zeros != 0) ans = max(ans, 0);

        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution obj;
        cout << obj.maxProduct(nums) << endl;
    }
    return 0;
}