// Problem: 3307. Find the K-th Character in String Game II (Hard)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii

function kthCharacter(k: number, operations: number[]): string {
    let ops = 0, i = 0;

    while (k % 2 == 0) {
        ops += operations[i];
        i++;
        k = Math.floor(k / 2);
    }

    i++;
    k = Math.floor(k / 2);

    while ( k > 0) {
        if (k % 2 == 1) {
            ops += operations[i];
        }
        i++;
        k = Math.floor(k / 2);
    }

    return String.fromCharCode(ops % 26 + 'a'.charCodeAt(0));
};