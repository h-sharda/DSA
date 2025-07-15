# Problem: 3136. Valid Word (Easy)
# Link: https://leetcode.com/problems/valid-word

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        vowel = False
        consonant = False

        for ch in word:
            if '0' <= ch and ch <= '9': 
                continue
            elif 'A' <= ch and ch <= 'Z':
                if ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U':
                    vowel = True
                else: 
                    consonant = True
            elif 'a' <= ch and ch <= 'z':
                if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u': 
                    vowel = True
                else: 
                    consonant = True
            else: 
                return False

        return vowel and consonant