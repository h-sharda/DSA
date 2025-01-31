// Date: 04/01/2025
// Number: 1930. Unique Length-3 Palindromic Subsequences (Medium)
// link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i =0; i <n; i++) {
            if (first[s[i]-'a'] == n) first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }

        for (int ch = 0; ch < 26; ch++) {
            int start = first[ch], end = last[ch];
            if ( end <= start ) continue;

            vector<int> v(26);
            for (int i = start +1; i< end; i++) v[s[i]-'a']++;
            for (int &i: v) if (i > 0) ans++;
        }
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution sol;
        cout << sol.countPalindromicSubsequence(s) << endl;
    }
    return 0;
}