// Problem: 1910. Remove All Occurrences of a Substring (Medium)
// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int n = s.size(), m = part.size();

        for (int i =0; i < n; i++) {
            ans += s[i];
            int k = ans.size();
            if (k >= m) if (ans.substr(k-m) == part) ans.resize(k-m);
        }

        return ans;
    }
};