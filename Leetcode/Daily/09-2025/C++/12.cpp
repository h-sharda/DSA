// Problem: 3227. Vowels Game in a String (Medium)
// Link: https://leetcode.com/problems/vowels-game-in-a-string

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char &ch: s) if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
};