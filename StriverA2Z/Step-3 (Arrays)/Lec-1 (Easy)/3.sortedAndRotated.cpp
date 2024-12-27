// LeetCode: 1752. Check if Array Is Sorted and Rotated (Easy)
// link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool rotated = false;
        for (int i =1; i < n; i++) {
            if ( nums[i-1] > nums[i] ) {
                if (rotated) return false;
                else {
                    if (nums[0] < nums.back()) return false;
                    rotated = true;
                }
            }
        }
        return true;
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
        for (int &i: nums) cin >> i;
        Solution ob;
        cout << ob.check(nums) << endl;      
    }
    return 0;
}