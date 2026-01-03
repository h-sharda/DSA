// Problem: 2185. Counting Words With a Given Prefix (Easy)
// Link: https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:
    bool isValid (string &a, string &pref) {
        int n = pref.size(), m = a.size();
        if ( m < n ) return false;
        for (int i =0; i < n; i++) if (pref[i] != a[i]) return false;
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string &s: words) if (isValid(s, pref)) ans++;
        return ans;
    }
};
