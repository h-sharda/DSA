// Problem: 1930. Unique Length-3 Palindromic Subsequences (Medium)
// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.size();
        
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int start = 0, end = n-1;
            while (start < n && s[start] != ch) start++;
            while (end >= 0 && s[end] != ch) end--;
            if ( end <= start ) continue;

            vector<int> v(26);
            for (int i = start +1; i< end; i++) v[s[i]-'a']++;
            for (int &i: v) if (i > 0) ans++;
        }
        
        return ans;
    }
};