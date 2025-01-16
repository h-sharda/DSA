// Leetcode: 5. Longest Palindromic Substring (Medium)
// Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    pair<int, int> palindrome (string &s, int i) {
        int n = s.size(), left = i - 1, right = i + 1;
        while (left >= 0 && s[left] == s[i]) left--;
        while (right < n && s[right] == s[i]) right++;

        while (left >= 0 && right < n && s[left] == s[right])  left--, right++;
        return {right - left - 1, left+1};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        
        for (int i =0; i < n; i++) {
            pair <int, int> p= palindrome(s, i);
            if (p.first > ans.size()) ans = s.substr(p.second, p.first);
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
        Solution obj;
        cout << obj.longestPalindrome(s) << endl;
    }
    return 0;
}