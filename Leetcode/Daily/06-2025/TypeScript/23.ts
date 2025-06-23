// Problem: 2081. Sum of k-Mirror Numbers (Hard)
// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers

function kMirror(k: number, n: number): number {
    function isValid(num: string) : boolean {
        let n = num.length;
        
        for (let i = 0; i < n / 2; i++) {
            if (num[i] != num[n - i - 1]) return false;
        }

        return true;
    }

    function baseTo10(num: string, base: number): number {
        let ans = 0, pow = 1;
        
        for (let i = num.length -1; i >= 0; i--) {
            ans += (num[i].charCodeAt(0) - '0'.charCodeAt(0)) * pow;
            pow *= base;
        }
        
        return ans;
    }

    function next(curr: string, base: number): string {
        let n = curr.length;

        let maxDigit = String.fromCharCode(base - 1 + '0'.charCodeAt(0));
        if (curr === maxDigit.repeat(n)) {
            return '1' + '0'.repeat(n - 1) + '1';
        }

        let ans = curr.split('');

        for (let i = Math.floor(n / 2); i < n; i++) {
            if (ans[i] < maxDigit) {
                let newChar = String.fromCharCode(curr[i].charCodeAt(0) + 1);                
                ans[n-i-1] = newChar;
                ans[i] = newChar;

                break;
            } else {
                ans[i] = ans[n-i-1] = '0';
            }
        }

        return ans.join('');
    }

    let ans = 0;
    let curr = "1";

    while (n > 0) {
        let dec = baseTo10(curr, k);

        if (isValid(dec.toString())) {
            ans += dec;
            n--;
        }

        curr = next(curr, k);
    }

    return ans;
};
