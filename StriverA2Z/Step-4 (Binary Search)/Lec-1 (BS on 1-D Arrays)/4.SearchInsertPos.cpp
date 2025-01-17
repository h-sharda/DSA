// Leetcode: 35. Search Insert Position (Easy)
// link: https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0, low = 0, high = nums.size()-1;
    
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid -1;
        }
    
        return low;
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
        int ans = ob.searchInsert(arr, k);
        cout << ans << endl;
    }
    return 0;
}