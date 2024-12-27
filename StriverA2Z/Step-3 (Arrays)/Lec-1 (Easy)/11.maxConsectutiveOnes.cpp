// Leetcode: 485. Max Consecutive Ones (Easy)
// link: https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), maxx = 0, curr = 0;
        for (int &i : nums) {
            if (i) curr++;
            else {
                maxx = max(maxx, curr);
                curr = 0;
            }
        }

        return max(curr, maxx);
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
        for (int &i : nums) cin >> i;

        Solution ob;
        cout << ob.findMaxConsecutiveOnes(nums) << "\n";      
    }
    return 0;
}