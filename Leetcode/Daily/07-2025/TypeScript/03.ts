// Problem: 3304. Find the K-th Character in String Game I (Easy)
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

function kthCharacter(k: number): string {
    let add = -1;
    while (k % 2 === 0) {
        add++;
        k = (k / 2) | 0;
    }

    while (k > 0) {
        if (k % 2 === 1) add++;
        k = ~~(k / 2);
    }

    return String.fromCharCode( (add % 26) + 'a'.charCodeAt(0));
};