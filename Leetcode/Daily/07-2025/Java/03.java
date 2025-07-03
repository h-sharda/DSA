// Problem: 3304. Find the K-th Character in String Game I (Easy)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class Solution {
    private void next(StringBuilder word) {
        int n = word.length();
        for (int i = 0; i < n; i++) word.append((char)((word.charAt(i) - 'a' + 1) % 26 + 'a'));
    }

    public char kthCharacter(int k) {
        StringBuilder word = new StringBuilder("a");
        
        while (word.length() < k) next(word);
        
        return word.charAt(k-1);
    }
}
