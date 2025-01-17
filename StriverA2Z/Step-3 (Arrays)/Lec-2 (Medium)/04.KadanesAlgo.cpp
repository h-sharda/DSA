// Leetcode: 53. Maximum Subarray (Medium)
// link: https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, curr = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) ans = max(ans, curr);
            curr += nums[i];
            if (curr < 0) curr = nums[i];
        }
        return max(ans, curr);
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

        Solution ob;
        cout << ob.maxSubArray(nums) << "\n";      
    }
    return 0;
}