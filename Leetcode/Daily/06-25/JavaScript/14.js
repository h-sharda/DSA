// Problem: 2566. Maximum Difference by Remapping a Digit (Easy)
// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function(num) {
    let str = num.toString();
    let n = str.length;
    let i = 0;

    let maxStr = str;
    while (i < n && str[i] == '9') i++;
    if (i != n) {
        let change = str[i];
        maxStr = str.split('').map(ch => ch === change ? '9' : ch).join('');
    }
    let max = parseInt(maxStr);

    let minStr = str.split('').map(ch => ch === str[0] ? '0' : ch).join('');
    let min = parseInt(minStr);

    return max -min;
};
