// Problem: 1790. Check if One String Swap Can Make Strings Equal (Easy)
// Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), x = -1, y = -1;

        for (int i =0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (x == -1) x = i;
                else if (y == -1) {
                    y = i;
                    if (s1[x] != s2[y] || s1[y] != s2[x]) return false;
                } else return false;
            }
        }

        return x == -1 || y != -1;
    }
};