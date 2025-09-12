// Problem: 2327. Number of People Aware of a Secret (Medium)
// Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret

class Solution {
public:
    int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(n + 1);
        v[1] = 1;

        for (int i = 1; i <= n; i++) 
            for (int j = i + delay; j < i + forget && j <= n; j++) v[j] = (v[j] + v[i]) % MOD;

        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++) ans = (ans + v[i]) % MOD;

        return ans;
    }
};
