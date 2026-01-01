// Leetcode: 136. Single Number (Easy)
// link: https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int &i: nums) xorr ^= i;
        return xorr;
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
        Solution obj;
        cout << obj.singleNumber(nums) << "\n";
    }
    return 0;
}