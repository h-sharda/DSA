// Problem: 3042. Count Prefix and Suffix Pairs I (Easy)
// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i

class Solution {
public:
    bool isValid (string &a, string &b) {
        int n = a.size(), m = b.size();
        if ( n > m) return false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return false;
            if (a[n-i-1] != b[m-i-1]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        
        for (int i =0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isValid(words[i], words[j])) ans++;
            }
        }
            
        return ans;
    }
};