// Problem: 2929. Distribute Candies Among Children II (Medium)
// Link: https://leetcode.com/problems/distribute-candies-among-children-ii

class Solution {
public:
    long long sum(int a, int b) {
        return (1ll * b * (b + 1) / 2) - (1ll * a * (a - 1) / 2);
    }

    long long distributeCandies(int n, int limit) {
        if (3 * limit < n) return 0;
        if (limit >= n) return 1ll * (n + 1) * (n + 2) / 2;

        long long ans = 0;

        if (n - limit <= limit) ans += sum(n-limit+1, limit+1);
        
        if (2 * limit - n + 1 > 0) ans += sum(2 * limit - n + 1, limit);
        else ans += sum(0, 3 * limit - n + 1);

        return ans;
    }
};