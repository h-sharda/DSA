// Problem: 1524. Number of Sub-arrays With Odd Sum (Medium)
// Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum

const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int e = 0, o = 0, ans = 0;
        
        for (int &num: arr) {
            int te = e, to = o;
            if (num % 2) {
                e = to;
                o = te + 1;
            } else {
                e = te + 1;
                o = to;
            }

            ans = (ans + o) % MOD;
        }

        return ans;
    }
};