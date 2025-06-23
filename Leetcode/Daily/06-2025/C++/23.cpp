// Problem: 2081. Sum of k-Mirror Numbers (Hard)
// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers

class Solution {
public:
    bool isValid(string num) {
        int n = num.size();
        
        for (int i = 0; i < n / 2; i++) {
            if (num[i] != num[n - i - 1]) return false;
        }

        return true;
    }

    long long baseTo10(string num, int base) {
        long long ans = 0, pow = 1;
        
        for (int i = num.size() -1; i >= 0; i--) {
            ans += (num[i]-'0') * pow;
            pow *= base;
        }
        
        return ans;
    }

    string next(string curr, int base) {
        int n = curr.size();

        if (curr == string(n, base-1 + '0')) {
            return "1" + string(n-1, '0') + "1";
        }

        string ans = curr;

        for (int i = n/2; i < n; i++) {
            if (curr[i] - '0' < base - 1) {
                ans[i] = ans[n-i-1] = curr[i] + 1;
                break;
            } else {
                ans[i] = ans[n-i-1] = '0';
            }
        }

        return ans;

    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        string curr = "1";

        while (n > 0) {
            long long dec = baseTo10(curr, k);
            if (isValid(to_string(dec))) {
                ans += dec;
                n--;
            }

            curr = next(curr, k);
        }

        return ans;
    }
};
