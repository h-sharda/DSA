// Problem: 2429. Minimize XOR (Medium)
// Link: https://leetcode.com/problems/minimize-xor

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0, bits = __builtin_popcount(num2);
        for (int i = 31; i >= 0; i--) {
            if (bits == 0) break;
            if ( (num1 >> i) & 1) {
                ans |= 1 << i;
                bits--;
            }
        }
        
        for (int i = 0; i < 32; i++) {
            if (bits == 0) break;
            if ( ((num1 >> i) & 1) == 0) {
                ans |= 1 << i;
                bits--;
            }
        }
        
        return ans;
    }
};