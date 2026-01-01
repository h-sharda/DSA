// Leetcode: 704. Binary Search (Easy)
// Link: https://leetcode.com/problems/binary-search/

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

        while (low<= high){
            int mid = low + (high-low)/2;
            if ( nums[mid] == target) return mid;
            else if ( nums[mid] > target ) high = mid-1;
            else low = mid +1;
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
        Solution obj;
        cout << obj.search(nums, target) << "\n";
    }
    return 0;
}