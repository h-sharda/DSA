// Problem: 3307. Find the K-th Character in String Game II (Hard)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii

class Solution {
    public char kthCharacter(long k, int[] operations) {
        int ops = 0, i = 0;

        while (k % 2 == 0) {
            ops += operations[i];
            i++;
            k /= 2;
        }

        i++;
        k /= 2;

        while ( k > 0) {
            if (k % 2 == 1) {
                ops += operations[i];
            }
            i++;
            k /= 2;
        }

        return (char)(ops % 26 + 'a');
    }
}

