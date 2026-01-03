// Problem: 2683. Neighboring Bitwise XOR (Medium)
// Link: https://leetcode.com/problems/neighboring-bitwise-xor

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size()      ;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (derived[i] == 1) curr = !curr;
        }

        return curr == 0;
    }
};