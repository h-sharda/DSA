// Problem: 2657. Find the Prefix Common Array of Two Arrays (Medium)
// Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common = 0;
        vector<int> ans(n), v(n+1);

        for (int i =0; i < n; i++) {
            if (v[A[i]] == 1) common++;
            v[A[i]]++;
            if (v[B[i]] == 1) common++;
            v[B[i]]++;
            
            ans[i] = common;
        }

        return ans;
    }
};