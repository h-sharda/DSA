// Problem: 3405. Count the Number of Arrays with K Matching Adjacent Elements (Hard)
// Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements

class Solution {
public:
    int MOD = 1e9 + 7;

    int modComb(int n, int r) {
        int ans = 1;
        
        for (int i = 1; i <= r; i++) {
            int mul = 1ll * (n - r + i) * modPow(i, MOD-2) % MOD;
            ans = 1ll * ans * mul % MOD;
        }

        return ans;
    }

    int modPow (int base, int exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base % MOD;

        int half = modPow(base, exp/2);

        int temp = (1ll * half * half) % MOD;

        if (exp % 2) return (1ll * temp * base) % MOD;
        return temp;
    }

    int countGoodArrays(int n, int m, int k) {
        int arrangeNums = 1ll * m * modPow(m-1, n-k-1) % MOD;
        int arrangePairs = modComb(n-1, k) % MOD;

        return 1ll * arrangeNums * arrangePairs % MOD;
    }
};
