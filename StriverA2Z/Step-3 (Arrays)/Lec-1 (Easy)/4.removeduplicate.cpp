// Leetcode: 26. Remove Duplicates from Sorted Array (Easy)
// link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1;
        while ( j < n) {
            if (nums[i] == nums[j]) j++;
            else nums[++i] = nums[j++];
        }
        return i+1;
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
        int len = ob.removeDuplicates(nums);
        for (int i = 0; i < len; i++) cout << nums[i] << " ";
        cout << endl;
    }
    return 0;
}