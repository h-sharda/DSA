// Problem: 1422. Maximum Score After Splitting a String (Easy)
// Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), maxx = INT_MIN, curr0 = 0, curr1 = 0;

        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') curr0++;
            else curr1++;
            maxx = max(maxx, curr0 - curr1);
        }
        
        if (s.back() == '1') curr1++;

        return maxx + curr1;
    }
};