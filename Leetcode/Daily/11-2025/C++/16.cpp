// Problem: 1513. Number of Substrings With Only 1s (Medium)
// Link: https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution {
public:
    int numSub(string s) {
        int n = s.size(), ans = 0, MOD = 1e9 + 7, one = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] - '0') one++;
            else {
                ans = (ans + 1ll * one * (one + 1) / 2) % MOD;
                one = 0;
            }
        }

        ans = (ans + 1ll * one * (one + 1) / 2) % MOD;
        return ans;
    }
};