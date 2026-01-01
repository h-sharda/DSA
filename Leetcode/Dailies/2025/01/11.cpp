// Date: 11/01/2025
// Number: 1400. Construct K Palindrome Strings (Medium)
// link: https://leetcode.com/problems/construct-k-palindrome-strings/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size() ) return false;
        
        int v[26] = {0};
        for (char &ch: s) v[ch - 'a']++;

        int count = 0;
        for (int i =0; i < 26; i++) if (v[i] % 2) count++;

        return count <= k;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution sol;
        cout << sol.canConstruct(s, k) << endl;
    }
    return 0;
}