// Problem: 1935. Maximum Number of Words You Can Type (Easy)
// Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broke(26);
        for (char &ch: brokenLetters) broke[ch-'a'] = true;

        int ans = 0, i = 0, n = text.size();
        while (i < n) {
            bool broken = false;
            while (i < n && text[i] != ' ') if (broke[text[i++]-'a']) broken = true;
            i++;

            if (!broken) ans++;
        }

        return ans;
    }
};