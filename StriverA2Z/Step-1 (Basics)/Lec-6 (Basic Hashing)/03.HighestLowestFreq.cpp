// Leetcode: 1838. Frequency of the Most Frequent Element (Medium)
// link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), ans = 0;
        int start = n-1, end = n-1, freq = 0;

        while (start >= 0 ) {
            if (nums[end]-nums[start] <= k) {
                k -= nums[end]-nums[start];
                freq++, start--;
            } else {
                ans = max(freq, ans);
                k += (freq-1) * (nums[end]-nums[end-1]);
                freq--, end--;
            }
        }

        return max(freq, ans);
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
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution sol;
        cout << sol.maxFrequency(nums, k) << endl;
    }
    return 0;
}