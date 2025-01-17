// Leetcode: 34. Find First and Last Position of Element in Sorted Array (Medium)
// link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = -1, last = -1, low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) first = mid;
            if (nums[mid] < target) low = mid + 1;
            else high = mid -1;
        }

        low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) last = mid;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid -1;
        }
    
        return {first, last};
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
        int k;
        cin >> k;
        Solution ob;
        vector<int> ans = ob.searchRange(arr, k);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}