// Problem: 3304. Find the K-th Character in String Game I (Easy)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class Solution {
public:
    void next(string &word) {
        int n = word.size();
        for (int i = 0; i < n; i++) word.push_back((word[i] - 'a' + 1) % 26 + 'a');
    }

    char kthCharacter(int k) {
        string word = "a";
        
        while (word.size() < k) next(word);
        
        return word[k-1];
    }
};
