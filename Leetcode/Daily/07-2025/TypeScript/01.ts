// Problem: 3330. Find the Original Typed String I (Easy)
// Link: https://leetcode.com/problems/find-the-original-typed-string-i

function possibleStringCount(word: string): number {
    let ans = 1;
    const n = word.length;

    for (let i = 1; i < n; i++) {
        if (word[i] === word[i-1]) ans++;
    }

    return ans;
};
