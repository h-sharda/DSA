// Leetcode: 162. Find Peak Element (Medium)
// link: https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n-2;

        while ( low <= high) {
            int mid = (high + low) / 2;

            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            if (nums[mid] < nums[mid+1]) low = mid + 1;
            else high = mid -1;
        }

        return -1;
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
        cout << ob.findPeakElement(arr) << endl;      
    }
    return 0;
}