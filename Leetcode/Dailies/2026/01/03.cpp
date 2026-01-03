// Problem: 1411. Number of Ways to Paint N × 3 Grid (Hard)
// Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfWays(int n) {
        long long ryr = 1, ryg = 1, rgr = 1, rgy = 1;
        long long yry = 1, yrg = 1, ygr = 1, ygy = 1;
        long long gry = 1, grg = 1, gyr = 1, gyg = 1;


        for (int i = 1; i < n; i++) {
            long long tryr = ryr, tryg = ryg, trgr = rgr, trgy = rgy;
            long long tyry = yry, tyrg = yrg, tygr = ygr, tygy = ygy;
            long long tgry = gry, tgrg = grg, tgyr = gyr, tgyg = gyg;

            ryr = (tyry + tyrg + tygy + tgry + tgrg) % MOD;
            ryg = (tyry + tygr + tygy + tgry) % MOD;
            rgr = (tgrg + tgry + tgyg + tyrg + tyry) % MOD;
            rgy = (tgrg + tgyr + tgyg + tyrg) % MOD;
            
            yry = (tryr + tryg + trgr + tgyr + tgyg) % MOD;
            yrg = (tryr + trgy + trgr + tgyr) % MOD;
            ygr = (tgyg + tgry + tgrg + tryg) % MOD;
            ygy = (tgyg + tgyr + tgrg + tryg + tryr) % MOD;

            gry = (trgr + tryg + tryr + tygr) % MOD;
            grg = (tyry + tyrg + tygy + tgry + tgrg) % MOD;
            gyr = (tygy + tyrg + tyry + trgy) % MOD;
            gyg = (tryr + tryg + trgr + tgyr + tgyg) % MOD;
        }

        return (ryr + ryg + rgr + rgy + yry + yrg + ygr + ygy + gry + grg + gyr + gyg) % MOD;
    }
};