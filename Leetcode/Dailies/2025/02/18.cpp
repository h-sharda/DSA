// Problem: 2375. Construct Smallest Number From DI String (Medium)
// Link: https://leetcode.com/problems/construct-smallest-number-from-di-string

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size(), i = 0;

        string ans(n+1, ' ');
        for (int i =0; i <= n; i++) ans[i] = i+'1';
        
        while (i < n) {
            while ( i < n && pattern[i] == 'I') i++;

            int start = i;
            while ( i < n && pattern[i] == 'D') i++;
            
            reverse(ans.begin() + start, ans.begin() + i + 1);
        }

        return ans;
    }
};