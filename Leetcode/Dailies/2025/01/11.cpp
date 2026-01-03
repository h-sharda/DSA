// Problem: 1400. Construct K Palindrome Strings (Medium)
// Link: https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size() ) return false;
        
        int v[26] = {0};
        for (char &ch: s) v[ch - 'a']++;

        int count = 0;
        for (int i =0; i < 26; i++) if (v[i] % 2) count++;

        return count <= k;
    }
};