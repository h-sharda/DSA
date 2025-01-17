// Leetcode: 33. Search in Rotated Sorted Array (Medium)
// link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while ( low <= high ) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target < nums[mid]) high = mid -1;
                else low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high]) low = mid +1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution ob;
        cout << ob.search(nums, target) << endl;
    }
    return 0;
}