// Leetcode: 410. Split Array Largest Sum (Hard)
// link: https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid(vector<int> &nums, int k, int maxSum) {
        int n = nums.size(), sum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] + sum > maxSum) {
                k--;
                sum = nums[i];
            } else sum += nums[i];
            if (k == 0) return false;
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {        
        int low = 0, high = 0, ans = -1;
        
        for (int &i: nums) {
            low = max(low, i);
            high += i;
        }

        while ( low <= high) {
            int mid = low + (high - low)/2;
            if (isValid(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        return ans;         
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int &i: nums) cin >> i;
        Solution obj;
        cout << obj.splitArray(nums, k) << "\n";
    }
    return 0;
}