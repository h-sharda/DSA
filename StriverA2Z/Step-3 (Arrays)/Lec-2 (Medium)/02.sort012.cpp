// Leecode: 75. Sort Colors (Medium)
// link: https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while ( mid <= high) {
            if (nums[mid] == 1) mid++;
            else if (nums[mid] == 0) swap(nums[mid++], nums[low++]);
            else swap(nums[mid], nums[high--]);
        }
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

        Solution obj;
        obj.sortColors(nums);

        for (int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << "\n";
    }
    return 0;
}