// Leetcode: 81. Search in Rotated Sorted Array II (Medium)
// link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

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
        int n = nums.size(), start = 0;

        if (nums[0] == nums[n-1]) {
            if (nums[0] == target) return true;
            while (start < n-1 && nums[start] == nums[start+1]) start++;
            start++;
        }

        int low = start, high = n-1;
        while ( low <= high ) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target < nums[mid]) high = mid -1;
                else low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high]) low = mid +1;
                else high = mid - 1;
            }
        }

        return false;
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