// Date: 08/01/2025
// Number: 3042. Count Prefix and Suffix Pairs I (Easy)
// link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

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

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        Solution sol;
        cout << sol.countPrefixSuffixPairs(words) << endl;
    }
    return 0;
}