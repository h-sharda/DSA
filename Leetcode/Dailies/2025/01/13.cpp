// Problem: 3223. Minimum Length of String After Operations (Medium)
// Link: https://leetcode.com/problems/minimum-length-of-string-after-operations

class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {};
        for (char &ch: s) freq[ch-'a']++;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (!freq[i]) continue;
            if (freq[i] % 2) ans++;
            else ans += 2;
        }

        return ans;
    }
};