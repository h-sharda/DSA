// Problem: 3304. Find the K-th Character in String Game I (Easy)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class Solution {
    public char kthCharacter(int k) {
        char ans = 'a';
        int add = -1;
        while ( k % 2 == 0 ) {
            k /= 2;
            add++;
        }

        while (k > 0) {
            if ( k % 2 == 1) add++;
            k /= 2;
        }

        return (char)(add % 26 + 'a');
    }
}
