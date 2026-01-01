// Leetcode: 268. Missing Number (Easy)
// link: https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return 1LL*(n*(n+1))/2 - sum;
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

        Solution obj;
        cout << obj.missingNumber(nums) << "\n";        
    }
    return 0;
}