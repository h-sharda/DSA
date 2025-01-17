// Date: 03/01/2025
// Number: 2270. Number of Ways to Split Array (Medium)
// link: https://leetcode.com/problems/number-of-ways-to-split-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL), curr = 0;
        int n = nums.size(), ans = 0;

        for (int i =0; i < n-1; i++) {
            curr += nums[i];
            sum -= nums[i];

            if ( curr >= sum ) ans++;
        }

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
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution sol;
        cout << sol.waysToSplitArray(nums) << endl;
    }
    return 0;
}