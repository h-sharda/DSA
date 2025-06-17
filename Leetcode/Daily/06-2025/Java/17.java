// Problem: 3405. Count the Number of Arrays with K Matching Adjacent Elements (Hard)
// Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements

class Solution {
    long MOD = (long)(1e9 + 7);

    long modComb(long n, long r) {
        long ans = 1;
        
        for (long i = 1; i <= r; i++) {
            long mul = (n - r + i) * modPow(i, MOD-2) % MOD;
            ans = ans * mul % MOD;
        }

        return ans;
    }

    long modPow (long base, long exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base % MOD;

        long half = modPow(base, exp/2);
        long temp = half * half % MOD;

        if (exp % 2 == 1) return temp * base % MOD;
        return temp;
    }

    public int countGoodArrays(int n, int m, int k) {
        long arrangeNums = m * modPow(m-1, n-k-1) % MOD;
        long arrangePairs = modComb(n-1, k) % MOD;

        return (int)(arrangeNums * arrangePairs % MOD);
    }    
}