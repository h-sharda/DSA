// Problem: 2425. Bitwise XOR of All Pairings (Medium)
// Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings

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