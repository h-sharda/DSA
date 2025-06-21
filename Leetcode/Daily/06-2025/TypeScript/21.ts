// Problem: 3085. Minimum Deletions to Make String K-Special (Medium)
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

function minimumDeletions(word: string, k: number): number {
    let freq = new Array(26).fill(0);
    
    for (let ch of word) {
        freq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    
    freq.sort((a, b) => a-b);
    let ans = Number.MAX_SAFE_INTEGER;
    
    for (let i = 25; i >= 0; i--) {
        let temp = 0;
        for (let j = i-1; j >= 0; j--) {
            temp += freq[j];
        }
        let target = freq[i] + k;
        for (let j = i; j < 26; j++) {
            if (freq[j] <= target) continue;
            temp += freq[j] - target;
        }
        ans = Math.min(ans, temp);
    }

    return ans;            
};