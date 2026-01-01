// Leetcode: 31. Next Permutation (Medium)
// link: https://leetcode.com/problems/next-permutation/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), j = n -1;
        while( j > 0 && nums[j-1] >= nums[j]) j--;

        if (j == 0 ) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int toSwap = j-1;
        while ( j < n && nums[toSwap] < nums[j]) j++;
        swap(nums[toSwap], nums[j-1]);
        reverse(nums.begin() + toSwap + 1, nums.end());
        return;
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

        Solution ob;
        ob.nextPermutation(nums);
        for (int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << "\n";   
    }
    return 0;
}