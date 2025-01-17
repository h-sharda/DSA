// Leetcode: 540. Single Element in a Sorted Array (Medium)
// link: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        if ( n == 1) return nums[0];
        if ( nums[0] != nums[1]) return nums[0];
        if ( nums[n-2] != nums[n-1]) return nums[n-1];
        
        int low = 1, high = n-2;

        while (low <= high) {
            int mid = (high + low ) /2;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1] ) return nums[mid];

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid+1]) low = mid + 1;
                else high = mid -1;
            } else {
                if (nums[mid] == nums[mid+1]) high = mid - 1;
                else low = mid + 1;
            }
        }

        return -1; // not reached;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        cout << ob.singleNonDuplicate(arr) << endl;      
    }
    return 0;
}