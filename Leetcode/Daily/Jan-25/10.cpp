// Date: 10/01/2025
// Number: 916. Word Subsets (Medium)
// link: https://leetcode.com/problems/word-subsets/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int v[26] = {0};
        for (string &s: words2) {
            int temp[26] = {0};
            for (char &ch: s) temp[ch-'a']++;
            for (int i = 0; i < 26; i++) v[i] = max(v[i], temp[i]);
        }

        vector<string> ans;
        for (string &s: words1) {
            int temp[26] = {0}, isValid = 1;
            
            for (char &ch: s) temp[ch-'a']++;
            for (int i = 0; i < 26; i++) {
                if ( v[i] > temp[i] ) {
                    isValid = 0;
                    break;
                }
            }
            
            if (isValid) ans.push_back(s);
        }
        
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> words1(n), words2(m);
        for (string &s: words1) cin >> s;
        for (string &s: words2) cin >> s;
        Solution sol;
        vector<string> ans = sol.wordSubsets(words1, words2);
        for (string &s: ans) cout << s << " ";
        cout << "\n";
    }
    return 0;
}