// Leetcode: 283. Move Zeroes (Easy)
// link: https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j =0;
        for (int i =0; i < n; i++) {
            if (nums[i] != 0 ) swap(nums[j++], nums[i]);
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
        for (int &i: nums) cin >> i;
        Solution ob;
        ob.moveZeroes(nums);
        for (int &i: nums) cout << i << " ";
        cout << endl;      
    }
    return 0;
}