class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for (char &ch: s) freq[ch-'a']++;

        int maxx = 0, minn = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2) maxx = max(maxx, freq[i]);
            else minn = min(minn, freq[i]);
        }

        return maxx-minn;
    }
};