// Problem: 916. Word Subsets (Medium)
// Link: https://leetcode.com/problems/word-subsets

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