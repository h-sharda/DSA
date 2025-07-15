// Problem: 3136. Valid Word (Easy)
// Link: https://leetcode.com/problems/valid-word

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool vowel = false, consonant = false;

        for (char &ch: word) {
            if ('0' <= ch && ch <= '9') continue;
            else if ('A' <= ch && ch <= 'Z') {
                if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') vowel = true;
                else consonant = true;
            } else if ('a' <= ch && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel = true;
                else consonant = true;
            } else return false;
        }

        return vowel && consonant;
    }
};