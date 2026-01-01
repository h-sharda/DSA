// Date: 15/01/2025
// Number: 2429. Minimize XOR (Medium)
// link: https://leetcode.com/problems/minimize-xor/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0, bits = __builtin_popcount(num2);
        for (int i = 31; i >= 0 && bits > 0; i--) {
            if ( (num1 >> i) & 1) {
                ans |= 1 << i;
                bits--;
            }
        }
        
        for (int i = 0; i < 32 && bits > 0; i++) {
            if ( ((num1 >> i) & 1) == 0) {
                ans |= 1 << i;
                bits--;
            }
        }
        
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
    }
    return 0;
}