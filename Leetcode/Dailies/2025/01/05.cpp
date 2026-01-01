// Problem: 2381. Shifting Letters II (Medium)
// Link: https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);
        
        for (const auto &it: shifts) {
            if (it[2] == 1) {
                shift[it[0]]++;
                shift[it[1]+1]--;
            } else {
                shift[it[0]]--;
                shift[it[1]+1]++;
            }
        }

        int change = 0;
        for (int i =0; i < n; i++) {
            change += shift[i];
            char ch = s[i] - 'a';
            ch = ((ch + change) % 26 + 26) % 26;
            s[i] = ch + 'a';
        }

        return s;
    }
};