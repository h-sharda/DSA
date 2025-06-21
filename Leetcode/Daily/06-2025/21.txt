// Problem: 3085. Minimum Deletions to Make String K-Special (Medium)
// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq [26] = {0}, ans = INT_MAX;
        for (char &ch: word) freq[ch - 'a']++;
        sort(freq, freq + 26);

        for (int i = 25; i >= 0; i--) {
            int temp = 0;
            for (int j = i-1; j >= 0; j--) {
                temp += freq[j];
            }
            int target = freq[i] + k;
            for (int j = i; j < 26; j++) {
                if (freq[j] <= target) continue;
                temp += freq[j] - target;
            }
            ans = min(ans, temp);
        }

        return ans;
        
    }
};
