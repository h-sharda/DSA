// Problem: 2197. Replace Non-Coprime Numbers in Array (Hard)
// Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st = { nums[0] };
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            int num = nums[i];
            
            while (!st.empty() && gcd(st.back(), num) != 1) {
                num = lcm(st.back(), num);
                st.pop_back();
            }

            st.push_back(num);
        }

        return st;
    }
};