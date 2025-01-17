#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool safeMultiply(long long a, long long b, long long& result) {
        if (b != 0 && a > LLONG_MAX / b) return false;
        result = a * b;
        return true;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long curGCD = nums[i];
            long long curLCM = nums[i];
            long long curProd = nums[i];

            for (int j = i; j < n; j++) {
                if (j > i) {
                    curGCD = gcd(curGCD, nums[j]);
                    curLCM = lcm(curLCM, nums[j]);
                    if (curLCM == LLONG_MAX) break; 
                    if (!safeMultiply(curProd, nums[j], curProd)) break; 
                }

                if (curProd == curGCD * curLCM) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};