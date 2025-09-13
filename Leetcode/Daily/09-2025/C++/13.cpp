// Problem: 3541. Find Most Frequent Vowel and Consonant (Easy)
// Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> a, b;

        for (char &ch: s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') a[ch]++;
            else b[ch]++;
        }

        int v = 0, c = 0;
        for (auto &[_, f]: b) c = max(c, f);
        for (auto &[_, f]: a) v = max(v, f);

        return v + c;
    }
};