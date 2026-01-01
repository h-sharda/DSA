// Leetcode: 189. Rotate Array (Medium)
// link: https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.begin()+n);
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int &i: nums) cin >> i;
        Solution ob;
        ob.rotate(nums, k);
        for (int &i: nums) cout << i << " ";
        cout << endl;
    }
    return 0;
}