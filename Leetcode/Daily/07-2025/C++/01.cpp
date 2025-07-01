// Problem: 3330. Find the Original Typed String I (Easy)
// Link: https://leetcode.com/problems/find-the-original-typed-string-i

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int n = word.size();

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i-1]) ans++;
        }

        return ans;        
    }
};