// Problem: 2559. Count Vowel Strings in Ranges (Medium)
// Link: https://leetcode.com/problems/count-vowel-strings-in-ranges

class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), count = 0;

        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++)
            v[i + 1] = isVowel(words[i][0]) && isVowel(words[i].back()) ? v[i] + 1 : v[i];

        int q = queries.size();
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++)
            ans[i] = v[queries[i][1] + 1] - v[queries[i][0]];

        return ans;
    }
};