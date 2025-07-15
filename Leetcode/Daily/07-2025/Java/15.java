// Problem: 3136. Valid Word (Easy)
// Link: https://leetcode.com/problems/valid-word

class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;

        boolean vowel = false, consonant = false;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            char ch = word.charAt(i);
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
}