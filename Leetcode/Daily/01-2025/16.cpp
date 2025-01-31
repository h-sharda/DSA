// Date: 16/01/2025
// Number: 2425. Bitwise XOR of All Pairings (Medium)
// link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), xorr1  = 0, xorr2 = 0;
        
        for (int i =0; i < n; i ++) xorr1 ^= nums1[i];
        for (int i =0; i < m; i ++) xorr2 ^= nums2[i];
        
        if (n % 2 == 0 && m % 2 == 0) return 0;
        else if (n % 2 == 0) return xorr1;
        else if (m % 2 == 0) return xorr2;
        else return xorr1 ^ xorr2;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums1(n), nums2(m);
        for (int i = 0; i < n; i++) cin >> nums1[i];
        for (int i = 0; i < m; i++) cin >> nums2[i];
        Solution sol;
        cout << sol.xorAllNums(nums1, nums2) << endl;
    }
    return 0;
}