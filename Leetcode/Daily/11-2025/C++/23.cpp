// Problem: 1262. Greatest Sum Divisible by Three (Medium)
// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mod0 = 0, mod1 = 0, mod2 = 0;
        
        for (int &num: nums) {
            int t0 = mod0, t1 = mod1, t2 = mod2;
            
            if (num % 3 == 0) {
                mod0 = t0 + num;
                if (t1) mod1 = t1 + num;
                if (t2) mod2 = t2 + num;
            } else if (num % 3 == 1) {
                if (t2) mod0 = max(t0, t2 + num);
                mod1 = max(t1, t0 + num);
                if (t1) mod2 = max(t2, t1 + num);
            } else {
                if (t1) mod0 = max(t0, t1 + num);
                if (t2) mod1 = max(t1, t2 + num);
                mod2 = max(t2, t0 + num);
            }
        }

        return mod0;
    }
};