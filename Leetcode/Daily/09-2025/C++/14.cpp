// Problem: 966. Vowel Spellchecker (Medium)
// Link: https://leetcode.com/problems/vowel-spellchecker

class Solution {
public:
    string toLower(string &str) {
        int n = str.size();
        
        string ans(n, ' ');
        for (int i = 0; i < n; i++) ans[i] = tolower(str[i]);
        
        return ans;
    }
    
    string rmVowel(string &str) {
        int n = str.size();
        
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            ans[i] = tolower(str[i]);
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') ans[i] = '_';
        }

        return ans;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size(), q = queries.size();
        unordered_map<string, int> exact, lower, noVowel;
        
        for (int i = n-1; i >= 0; i--) {
            exact[wordlist[i]] = i;
            lower[toLower(wordlist[i])] = i;
            noVowel[rmVowel(wordlist[i])] = i;
        }

        vector<string> ans(q);
        for (int i = 0; i < q; i++) {
            auto str1 = toLower(queries[i]), str2 = rmVowel(queries[i]);
            if (exact.contains(queries[i])) ans[i] = queries[i];
            else if (lower.contains(str1)) ans[i] = wordlist[lower[str1]];
            else if (noVowel.contains(str2)) ans[i] = wordlist[noVowel[str2]];
            else ans[i] = "";
        }

        return ans;
    }
};