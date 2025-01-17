// Leetcode: 153. Find Minimum in Rotated Sorted Array (Medium)
// link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1;

        while ( low <= high ) {
            int mid = (low + high) / 2;
            if (mid < n-1 && nums[mid] > nums[mid+1]) return nums[mid+1];
            
            if (nums[mid] >= nums[low]) low = mid +1;    
            else high = mid - 1;
        }

        return nums[0];
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
        cout << ob.findMin(nums) << endl;
    }
    return 0;
}